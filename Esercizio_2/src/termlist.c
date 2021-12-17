#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "termlist.h"
#include "char_array.h"
#include "edit_distance.h"

#define INITIAL_CAPACITY 2

struct term_list
{
  char *word;
  Array *corrections;
  int edit_d;
};

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
  list->word = (char *)malloc(sizeof(char));
  strcpy(list->word, string);
  list->corrections = array_create();
  if (list->corrections == NULL)
  {
    fprintf(stderr, "termlist_create: unable to allocate memory for the array of corrections\n");
    exit(EXIT_FAILURE);
  }
  list->edit_d = (int)strlen(list->word);

  return list;
}

unsigned long termlist_size(TermList *list)
{
  if (list == NULL)
  {
    fprintf(stderr, "termlist_size: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  unsigned long size = array_size(list->corrections);
  return size;
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
  // Termlist is empty
  if (termlist_size(list) == 0)
    {
      array_add(list->corrections, string);
      termlist_set_edit(list, edit_distance_dyn(list->word, string));
    }
  else 
  {
    // The string has the same edit distance of the struct,
    // so it adds the string to the internal array 
    if (edit_distance_dyn(list->word,string) == list->edit_d)
      array_add(list->corrections, string);
    // The string has not the same edit distance of the struct, 
    // so it clears the list, add the string with different edit distance
    // and set the new value of edit distance
    else
    {
    termlist_clear(list);
    array_add(list->corrections, string);
    termlist_set_edit(list, edit_distance_dyn(list->word, string));
    }
  }
}

char *termlist_get_word(TermList *list)
{
  if (list == NULL)
  {
    fprintf(stderr, "termlist_get_word: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  return list->word;
}

char *termlist_get_corr(TermList *list, unsigned long index)
{
  if (list == NULL)
  {
    fprintf(stderr, "termlist_get_corr: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  if (index >= array_size(list->corrections))
  {
    fprintf(stderr, "termlist_get_corr: index out of bound\n");
    exit(EXIT_FAILURE);
  }
  return array_get(list->corrections, index);
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
  array_free_memory(list->corrections);
  free(list->word);
  free(list);
}

void termlist_print(TermList *list)
{
  if (list == NULL)
  {
    fprintf(stderr, "print_list: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  printf("\nWORD EXAMINED <%s> :\n", list->word);
  unsigned long size = array_size(list->corrections);
  printf("DICTIONARY CORRECTIONS WITH EDIT-DISTANCE <%d> :\n", list->edit_d);
  for (unsigned long i = 0; i < size; i++)
    printf("- <%s>\n", (char *)array_get(list->corrections, i));
}

void termlist_clear(TermList *list)
{
  array_free_memory(list->corrections);
  list->corrections = array_create();
  termlist_set_edit(list,(int)strlen(list->word));
}

/**
 ** Sets the new value for the edit distance
 ** 
 ** @param Termlist *
 ** @param int
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