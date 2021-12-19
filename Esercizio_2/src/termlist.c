#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "termlist.h"
#include "string_array.h"
#include "edit_distance.h"

#define INITIAL_CAPACITY 2

struct term_list
{
  char * reference_string;
  Array * string_array;
  int edit_d;
};

static void termlist_clear(TermList *list);
static void termlist_set_edit(TermList *list, int edit_d);

TermList *termlist_create(char *string)
{
  if (string == NULL)
  {
    fprintf(stderr, "termlist_create: the word cannot be null\n");
    exit(EXIT_FAILURE);
  }
  TermList *list = (TermList *)malloc(sizeof(TermList));
  if (list == NULL)
  {
    fprintf(stderr, "termlist_create: unable to allocate memory for the terms list\n");
    exit(EXIT_FAILURE);
  }
  list->reference_string = (char *)malloc(sizeof(char));
  strcpy(list->reference_string, string);
  list->string_array = array_create();
  if (list->string_array == NULL)
  {
    fprintf(stderr, "termlist_create: unable to allocate memory for string array\n");
    exit(EXIT_FAILURE);
  }
  list->edit_d = (int)strlen(list->reference_string);

  return (list);
}

unsigned long termlist_size(TermList *list)
{
  if (list == NULL)
  {
    fprintf(stderr, "termlist_size: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  unsigned long size = array_size(list->string_array);
  return (size);
}

void termlist_add(TermList *list, char *string)
{
  if (list == NULL)
  {
    fprintf(stderr, "termlist_add: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  if (string == NULL)
  {
    fprintf(stderr, "termlist_add: string cannot be null\n");
    exit(EXIT_FAILURE);
  }
  int dist = edit_distance_dyn(list->reference_string,string);
  
  if(dist != list->edit_d) // if edit distance is not the same of Termlist,
                           // it clears all strings in the array 
    termlist_clear(list);
  array_add(list->string_array, string);
  termlist_set_edit(list,dist);
}

char *termlist_get_reference_string(TermList *list)
{
  if (list == NULL)
  {
    fprintf(stderr, "termlist_get_reference_string: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  return (list->reference_string);
}

char *termlist_get_string(TermList *list, unsigned long index)
{
  if (list == NULL)
  {
    fprintf(stderr, "termlist_get_string: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  if (index >= array_size(list->string_array))
  {
    fprintf(stderr, "termlist_get_string: index out of bound\n");
    exit(EXIT_FAILURE);
  }
  return array_get(list->string_array, index);
}

int termlist_get_edit_distance(TermList *list)
{
  if (list == NULL)
  {
    fprintf(stderr, "termlist_get_edit_distance: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  return list->edit_d;
}

void termlist_free(TermList *list)
{
  if (list == NULL)
  {
    fprintf(stderr, "termlist_free: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  array_free_memory(list->string_array);
  free(list->reference_string);
  free(list);
}

void termlist_print(TermList *list)
{
  if (list == NULL)
  {
    fprintf(stderr, "print_list: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  printf("\nWORD EXAMINED <%s> :\n", list->reference_string);
  unsigned long size = array_size(list->string_array);
  printf("DICTIONARY string_array WITH EDIT-DISTANCE <%d> :\n", list->edit_d);
  for (unsigned long i = 0; i < size; i++)
    printf("- <%s>\n", (char *)array_get(list->string_array, i));
}
 /**
  * Free the memory occupied by string_array and it creates a new empty one
  * 
  * @param list: the pointer of the struct TermList
  */
static void termlist_clear(TermList *list)
{
  array_free_memory(list->string_array);
  list->string_array = array_create();
}

/**
 * Set the edit distance value corresponding to that
 * between the reference string and the strings in the array
 * 
 * @param list: the pointer of the struct TermList
 * @param edit_d: the edit distance value
 */
static void termlist_set_edit(TermList *list, int edit_d)
{
  if (edit_d < 0)
  {
    fprintf(stderr, "termlist_set_edit: edit distance cannot be less than zero\n");
    exit(EXIT_FAILURE);
  }
  list->edit_d = edit_d;
}