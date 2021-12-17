#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editdistance.h"
#include "termlist.h"
#include "array.h"

#define INITIAL_CAPACITY 2

struct term_list{
  char* word;
  Array* corrections;
  unsigned long edit_d;
};

static void clear_terms(TermList* list);

TermList* termlist_create(char* string) {
  if(string == NULL){
    fprintf(stderr,"termlist_create: the word cannot be null\n");
    exit(EXIT_FAILURE);
  }
  TermList* list = (TermList*)malloc(sizeof(TermList));
  if(list == NULL){
    fprintf(stderr, "termlist_create: unable to allocate memory for the terms list\n");
    exit(EXIT_FAILURE);
  }
  list->word = (char*)malloc(sizeof(char));
  strcpy(list->word,string);
  list->corrections = array_create();
  if(list->corrections == NULL){
    fprintf(stderr, "termlist_create: unable to allocate memory for the array of corrections\n");
    exit(EXIT_FAILURE);
  }
  list->edit_d = strlen(list->word);
  
  return (list);
}

unsigned long termlist_size(TermList* list){
  if(list == NULL){
    fprintf(stderr,"termlist_size: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  unsigned long size = array_size(list->corrections);
  return (size);
}

void termlist_add(TermList* list, char* string){
  if(list == NULL){
    fprintf(stderr,"termlist_add: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  if(string == NULL){
    fprintf(stderr,"termlist_add: string cannot be null\n");
    exit(EXIT_FAILURE);
  }
  
  unsigned long dist = edit_distance_dyn(list->word,string);
  //primo termine 
  unsigned long size = array_size(list->corrections);
  if(size == 0){
    list->edit_d = dist;
    array_add(list->corrections,string);
  }
  else {
    if(dist > list->edit_d)
      return;
    if(dist == list->edit_d){
      array_add(list->corrections,string);
      return;
    }
    clear_terms(list);
    list->edit_d = dist;
    array_add(list->corrections,string);
  }
}

char* termlist_get_word(TermList* list){
  if(list == NULL){
    fprintf(stderr,"termlist_get_word: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  return (list->word);
}

char* termlist_get_corr(TermList* list, unsigned long index){
  if(list == NULL){
    fprintf(stderr,"termlist_get_corr: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  if(index >= array_size(list->corrections)){
    fprintf(stderr,"termlist_get_corr: index out of bound\n");
    exit(EXIT_FAILURE);
  }
  return array_get(list->corrections,index);
}

void termlist_free(TermList* list){
  if(list == NULL){
    fprintf(stderr,"termlist_free: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  array_free_memory(list->corrections);
  free(list->word);
  free(list);
}

void termlist_print(TermList* list){
  if(list == NULL){
    fprintf(stderr, "print_list: list cannot be null\n");
    exit(EXIT_FAILURE);
  }
  printf("WORD EXAMINED <%s> EDIT-DISTANCE <%lu> :\n",list->word,list->edit_d);
  unsigned long size = array_size(list->corrections);
  for(unsigned long i = 0; i < size; i++)
    printf("- <%s>\n",(char*)array_get(list->corrections,i));
}

static void clear_terms(TermList* list){
  array_free_memory(list->corrections);
  list->corrections = array_create();
}