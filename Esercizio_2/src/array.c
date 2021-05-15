#include <stdlib.h>
#include <stdio.h>
#include "array.h"

#define INITIAL_CAPACITY 2

struct array {
  void** array;
  unsigned long capacity;
  unsigned long num_elem;
};

static void array_resize(Array*,size_t);

Array* array_create() {
  Array* result = (Array*) malloc(sizeof(Array));
  if(result == NULL) {
    fprintf(stderr,"Array_new: unable to allocate memory for the array");
    exit(EXIT_FAILURE);
  }
  result->capacity = INITIAL_CAPACITY;
  result->array = (void**) malloc(sizeof(void*) * result->capacity);
  if(result->array == NULL) {
    fprintf(stderr,"Array_new: unable to allocate memory for the internal array");
    exit(EXIT_FAILURE);
  }
  result->num_elem = 0;
  return result;
}

void array_add(Array* sa, void* obj) {
  if(sa == NULL){
    fprintf(stderr,"array_add : array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(obj == NULL){
    fprintf(stderr,"array_add : object parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(sa->capacity == sa->num_elem) {
    array_resize(sa, sa->capacity * 2);
  }
  
  sa->array[sa->num_elem] = obj;
  sa->num_elem++;
}

void* array_get(Array* sa, unsigned long i) {
  if(sa == NULL){
    fprintf(stderr,"array_get: ordered_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(i >= sa->num_elem){
    fprintf(stderr,"array_get: Index %lu is out of the array bounds",i);
    exit(EXIT_FAILURE);
  }
  return sa->array[i];
}

void** array_get_internal(Array* sa) {
  if(sa == NULL){
    fprintf(stderr,"array_get: ordered_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  return sa->array;
}

unsigned long array_size(Array* sa) {
  if(sa == NULL){
    fprintf(stderr,"array_size: array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  return sa->num_elem;
}

void array_free_memory(Array *sa){
  if(sa == NULL){
    fprintf(stderr,"array_free_memory: array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  free(sa->array);
  free(sa);
}

static void array_resize(Array* sa, size_t memsize) {
  sa->capacity = memsize;
  sa->array = (void**) realloc(sa->array, sa->capacity * sizeof(void*));
  
  if(sa->array == NULL){
    fprintf(stderr,"array_resize: unable to allocate memory for the internal array");
    exit(EXIT_FAILURE);
  }
}

