#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "char_array.h"

#define INITIAL_CAPACITY 2

struct array {
  char** array;
  unsigned long el_num;
  unsigned long array_capacity;
};

Array* array_create() {
  Array* array = (Array*) malloc(sizeof(Array));
  if(array == NULL) {
    fprintf(stderr,"array_create: unable to allocate memory for the array");
    exit(EXIT_FAILURE);
  }
  array->array = (char**)malloc(INITIAL_CAPACITY*sizeof(char*));
  if(array->array == NULL) {
    fprintf(stderr,"array_create: unable to allocate memory for the internal array");
    exit(EXIT_FAILURE);
  }
  array->el_num = 0;
  array->array_capacity = INITIAL_CAPACITY;
  
  return (array);
}

void array_add(Array* array, char* element) {
  if(array == NULL){
    fprintf(stderr,"array_add : array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(element == NULL){
    fprintf(stderr,"array_add : element parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  
  if(array->el_num >= array->array_capacity) {
    array->array = (char**)realloc(array->array,2*(array->array_capacity)*sizeof(char*));
    if(array->array == NULL){
      fprintf(stderr,"array_add: unable to reallocate memory to host the new element");
      exit(EXIT_FAILURE);
    }
    array->array_capacity = 2*array->array_capacity;
  }
  array->array[array->el_num] = (char*)malloc(sizeof(char));
  strcpy(array->array[array->el_num],element);
  (array->el_num)++;
}

char* array_get(Array* array, unsigned long i) {
  if(array == NULL){
    fprintf(stderr,"array_get: ordered_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(i >= array->el_num){
    fprintf(stderr,"array_get: index %lu is out of the array bounds",i);
    exit(EXIT_FAILURE);
  }
  return (array->array)[i];
}

unsigned long array_size(Array* array) {
  if(array == NULL){
    fprintf(stderr,"array_size: array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  return (array->el_num);
}

void array_free_memory(Array *array){
  if(array == NULL){
    fprintf(stderr,"array_free_memory: array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  for(unsigned long i = 0; i < array_size(array); i++){
    char* element = array_get(array,i);
    free(element);
  }
  free(array->array);
  free(array);
}