#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string_array.h"

#define INITIAL_CAPACITY 2

struct string_array
{
  char **array;
  unsigned long el_num;
  unsigned long array_capacity;
};

Array *array_create()
{
  Array *sa = (Array *)malloc(sizeof(Array));
  if (sa == NULL)
  {
    fprintf(stderr, "array_create: unable to allocate memory for the array");
    exit(EXIT_FAILURE);
  }
  sa->array = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
  if (sa->array == NULL)
  {
    fprintf(stderr, "array_create: unable to allocate memory for the internal array");
    exit(EXIT_FAILURE);
  }
  sa->el_num = 0;
  sa->array_capacity = INITIAL_CAPACITY;

  return (sa);
}

void array_add(Array *sa, char *element)
{
  if (sa == NULL)
  {
    fprintf(stderr, "array_add : array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if (element == NULL)
  {
    fprintf(stderr, "array_add : element parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }

  if (sa->el_num >= sa->array_capacity) // reached capacity, increasing capacity
  {
    sa->array = (char **)realloc(sa->array, 2 * (sa->array_capacity) * sizeof(char *));
    if (sa->array == NULL)
    {
      fprintf(stderr, "array_add: unable to reallocate memory to host the new element");
      exit(EXIT_FAILURE);
    }
    sa->array_capacity = 2 * sa->array_capacity;
  }
  
  sa->array[sa->el_num] = (char *)malloc(sizeof(char));
  strcpy(sa->array[sa->el_num], element);
  (sa->el_num)++;
}

char *array_get(Array *sa, unsigned long i)
{
  if (sa == NULL)
  {
    fprintf(stderr, "array_get: ordered_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if (i >= sa->el_num)
  {
    fprintf(stderr, "array_get: index %lu is out of the array bounds", i);
    exit(EXIT_FAILURE);
  }
  return (sa->array)[i];
}

unsigned long array_size(Array *sa)
{
  if (sa == NULL)
  {
    fprintf(stderr, "array_size: array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  return (sa->el_num);
}

void array_free_memory(Array *sa)
{
  if (sa == NULL)
  {
    fprintf(stderr, "array_free_memory: array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  for (unsigned long i = 0; i < array_size(sa); i++)
  {
    char *string = array_get(sa, i);
    free(string);
  }
  free(sa->array);
  free(sa);
}