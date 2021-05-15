#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editdistance.h"
#include "termlist.h"

#define INITIAL_CAPACITY 2

struct list_term{
  char* word;
  char** array_correction;
  unsigned long array_cap;
  unsigned long num_elem;
  unsigned long edit_d;
};

static void set_edit(ListTerm* list,unsigned long distance);
static void clear_terms(ListTerm* list);

ListTerm* create_ListTerm(char* string) {
  if(string == NULL){
    fprintf(stderr,"the word cannot be null\n");
    exit(EXIT_FAILURE);
  }
  ListTerm* list = (ListTerm*)malloc(sizeof(ListTerm));
  if(list == NULL){
    fprintf(stderr, "create_ListTerm: unable to allocate memory for the terms list\n");
    exit(EXIT_FAILURE);
  }
  list->word = string;
  list->array_correction = (char**)malloc(sizeof(char*)*INITIAL_CAPACITY);
  if(list->array_correction == NULL){
    fprintf(stderr, "create_ListTerm: unable to allocate memory for the array of corrections\n");
    exit(EXIT_FAILURE);
  }
  list->array_cap = INITIAL_CAPACITY;
  list->num_elem = 0;
  list->edit_d = strlen(list->word);
  
  return list;
}

void print_list(ListTerm* list){
  if(list == NULL){
    fprintf(stderr, "print: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  printf("The word examined is %s\nThe terms list with edit distance %lu is:\n",list->word,list->edit_d);
  for(unsigned long i = 0; i < list->num_elem; i++)
    printf(" - %s\n",list->array_correction[i]);
}

int is_empty(ListTerm* list){
  if(list == NULL){
    fprintf(stderr, "is_empty: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  return (list->num_elem == 0)? 1:0;
}

void add_term(ListTerm* list, char* string){
  if(list == NULL){
    fprintf(stderr,"add_term: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  if(string == NULL){
    fprintf(stderr,"add_term: string cannot be null\n");
    exit(EXIT_FAILURE);
  }
  unsigned long dist = edit_distance_dyn(list->word,string);
  if(list->num_elem == 0){
    set_edit(list,dist);
    list->array_correction[list->num_elem] = string;  
  }
  else {
    if(list->edit_d < dist)
      return;
    if(list->edit_d > dist){
      clear_terms(list);
      set_edit(list,dist);
      list->array_correction[list->num_elem] = string;
      list->num_elem++;
      return;
    }
    if(list->array_cap <= list->num_elem)
      list->array_cap *= 2; 
    list->array_correction[list->num_elem] = string;
    list->num_elem++;
  }
}

char* get_word(ListTerm* list){
  if(list == NULL){
    fprintf(stderr,"get_word: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  return list->word;
}

char* get_correction(ListTerm* list, unsigned long index){
  if(list == NULL){
    fprintf(stderr,"get_correction: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  return list->array_correction[index];
}

void free_list(ListTerm* list){
  clear_terms(list);
  free(list->word);
  free(list->array_correction);
  free(list);
}

static void set_edit(ListTerm* list,unsigned long distance){
  list->edit_d = distance; 
}

static void clear_terms(ListTerm* list){
  for(unsigned long i = 0; i < list->num_elem; i++)
    free(list->array_correction[i]);
  set_edit(list,strlen(list->word));
  list->array_cap = INITIAL_CAPACITY;
  list->num_elem = 0;
}