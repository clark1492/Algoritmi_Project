#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "merge_binary_insertion_sort.h"

static void merge_sort(void* base, void* temp_array, unsigned long start, unsigned long end, size_t memSize, compare fun, unsigned long k_value,size_t nitems);
static void merge(void* base, void* temp_array, unsigned long start, unsigned long mid, unsigned long end, size_t size, compare fun);
static void insertion_sort(void *base, unsigned long start,unsigned long end, size_t memSize, compare fun);
static unsigned long binary_search(void* base, void* elem,  unsigned long start,  unsigned long end, size_t memSize, compare fun);

void merge_binary_insertion_sort(void* base, size_t nitems, size_t memSize, compare fun, unsigned long k_value) {
  if(base == NULL) {
    fprintf(stderr,"merge_binary_insertion_sort: array parameter cannot be NULL\n");
    exit(EXIT_FAILURE);
  }
  if(fun == NULL) {
    fprintf(stderr,"merge_binary_insertion_sort: compare parameter cannot be NULL\n");
    exit(EXIT_FAILURE);
  }
  if(memSize <= 0) {
    fprintf(stderr,"merge_binary_insertion_sort: size of the array cannot be equal-less than zero\n");
    exit(EXIT_FAILURE);
  }
  if(k_value >= nitems) {
    fprintf(stderr,"merge_binary_insertion_sort: k_value cannot be equal_greater than number of items of the array or less than zero\n");
    exit(EXIT_FAILURE);
  }
  char* temp_array = (char*) malloc(sizeof(char) * memSize * nitems);
  
  if(temp_array == NULL){
    fprintf(stderr,"merge_binary_insertion_sort: anable to allocate memory for the temporary arry\n");
    exit(EXIT_FAILURE);
  }
  merge_sort(base, temp_array, 0, nitems-1, memSize, fun, k_value, nitems );
  free(temp_array);
}

static void merge_sort(void* base, void* temp_array, unsigned long start, unsigned long end,  size_t memSize, compare fun, unsigned long k_value, size_t nitems) {
  if(end - start <= k_value ){
    insertion_sort(base,start,end,memSize,fun);
    return;
  }
  unsigned long mid = start + ((end - start)/2);
  merge_sort(base, temp_array, start, mid, memSize, fun,k_value,nitems);
  merge_sort(base, temp_array, mid+1, end, memSize, fun,k_value,nitems);
  merge(base, temp_array, start, mid, end, memSize, fun);
}

static void merge(void* array, void* temp_array, unsigned long start, unsigned long mid, unsigned long end, size_t memSize, compare fun) {
  
  char* left_elem;
  char* right_elem;
  char* temp_elem;
 
  unsigned long left_index = start;
  unsigned long right_index = mid +1;
  unsigned long array_index = start; 
  
  while(left_index <= mid && right_index <= end){
    
    left_elem = (char*)array + (left_index * memSize);
    right_elem = (char*)array + (right_index * memSize);
    
    if(fun(left_elem, right_elem) < 0){
      temp_elem = (char*)temp_array + (array_index * memSize);
      memcpy(temp_elem, left_elem, memSize);
      left_index++;
      array_index++;
     
    }
    else {
      temp_elem = (char*)temp_array + (array_index * memSize);
      memcpy(temp_elem, right_elem, memSize);
      right_index++;
      array_index++;
      
    }
  }
  while(left_index <= mid){
    left_elem = (char*)array + (left_index * memSize);
    temp_elem = (char*)temp_array + (array_index * memSize);
    memcpy(temp_elem, left_elem, memSize);
    left_index++;
    array_index++;
    

  }

  while(right_index <= end){
    right_elem = (char*)array + (right_index * memSize);
    temp_elem = (char*)temp_array + (array_index * memSize);
    memcpy(temp_elem, right_elem, memSize);
    right_index++;
    array_index++;
  
  }
  
  for(array_index = start; array_index <= end; array_index++){
    left_elem = (char*)array + (array_index*memSize);
    temp_elem = (char*)temp_array + (array_index*memSize);
    memcpy(left_elem,temp_elem,memSize);
  }
}


static void insertion_sort(void *base, unsigned long start, unsigned long end, size_t memSize, compare fun){
  unsigned long i,j;
  char* temp =(char*) malloc(sizeof(char));
  
  if(temp == NULL){
    fprintf(stderr,"merge_binary_insertion_sort: anable to allocate memory for the temporary arry\n");
    exit(EXIT_FAILURE);
  }
  
  for(j = start + 1; j <= end; j++){
    i = j-1;
    char* prev = (char*)base + j*memSize;
    char* curr = prev - memSize;
    unsigned long loc = binary_search(base,prev,start,i,memSize,fun);
    while(i >= loc && curr >= (char*)base + (start*memSize)){
      memcpy (temp,prev,memSize);
      memcpy(prev,curr,memSize);
      memcpy(curr,temp,memSize);
      prev = curr;
      curr -= memSize;
      i--;
    }
  }
  free(temp);
}

static unsigned long binary_search(void* base, void* item, unsigned long low, unsigned long high, size_t memSize, compare fun){
  while (low <= high) {
    unsigned long middle = low + (high - low)/2;

    char* selected = (char*)base + (middle * memSize);
    int result = (fun(item,selected));

    if(result < 0){
      if(middle != 0)
        high = middle -1;
      else
        return 0;
    }
    else
      low = middle + 1;
  }
  return low;
}