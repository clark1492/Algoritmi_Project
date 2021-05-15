#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "termlist.h"
#include "array.h"

#define BUFF_SIZE 1024

static unsigned long num_list;

static void load_data(const char* filepath, Array* arr_str){
  char *read_line_p;
  char buffer[BUFF_SIZE];
  FILE *fp;
  printf("\nLoading data from file %s\n",filepath);
  fp = fopen(filepath,"r");
  if(fp == NULL){
    fprintf(stderr,"main: unable to open the file");
    exit(EXIT_FAILURE);
  }
  while(fgets(buffer,BUFF_SIZE,fp) != NULL){
    read_line_p = malloc((strlen(buffer)+1)*sizeof(char));
    if(read_line_p == NULL){
      fprintf(stderr,"main: unable to allocate memory for the read line");
      exit(EXIT_FAILURE);
    }
    strcpy(read_line_p,buffer);
    char* punt = " ,;.:-_";
    char *token = strtok(read_line_p,punt);
    while(token != NULL){
      array_add(arr_str,token);
      token = strtok(NULL,punt);
    }
  }
  fclose(fp);
  printf("\nData loaded\n");
}

static void min_edit_distance(ListTerm** list, Array* word, Array* dict){
  unsigned long num_words = array_size(word);
  num_list = num_words;
  for(unsigned long i  = 0; i < num_words; i++){
    list[i] = create_ListTerm(array_get(word,i));
    unsigned long num_corr = array_size(dict);
    for(unsigned long j = 0; j < num_corr; j++)
      add_term(list[i],array_get(dict,j));
  }
}

static void print_every_list(ListTerm** list){
  for(unsigned long i = 0; i < num_list; i++){
    print_list(list[i]);
  }
}

static void test_with_edit_distance(const char* filepath_1, const char* filepath_2){
  Array* text = array_create();
  Array* dict = array_create();
  load_data(filepath_1,text);
  load_data(filepath_2,dict);
  unsigned long num_wrd = array_size(text);
  ListTerm** list = (ListTerm**)malloc(sizeof(ListTerm*)* num_wrd);
  min_edit_distance(list,text,dict);
  print_every_list(list);
}

int main(int argc, char const *argv[]){
  if(argc < 3){
    printf("Usage: app <filename1> <filename2>");
    exit(EXIT_FAILURE);
  }

  test_with_edit_distance(argv[1],argv[2]);

  return (EXIT_SUCCESS);
}

