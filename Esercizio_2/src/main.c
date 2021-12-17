#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "termlist.h"
#include "array.h"

#define BUFF_SIZE 1024
#define DELIM " ,;.:\"'-?!\n"

static  void print_array(Array* array);

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
    char* punct = DELIM;
    char *token = strtok(read_line_p,punct);
    while(token != NULL){
      if(token[0] >= 'A' && token[0] <= 'Z')
        token[0]+= (char)32;
      array_add(arr_str,token);
      token = strtok(NULL,punct);
    }
  }
  fclose(fp);
  printf("\nData loaded\n");
}

static void min_edit_distance(TermList* list, Array* array){
  unsigned long size_dict = array_size(array);
  for(unsigned long i = 0; i < size_dict; i++){
    char* exam = (char*)array_get(array,i);
    termlist_add(list,exam);
  }
}

static void test_with_edit_distance(const char* filepath_1, const char* filepath_2){
  Array* text = array_create();
  load_data(filepath_1,text);
  Array* dict = array_create();
  load_data(filepath_2,dict);
  unsigned long num_wrd = array_size(text);
  
  TermList** list = (TermList**)malloc(sizeof(TermList*)*num_wrd);
  for(unsigned long i = 0; i < num_wrd; i++){
    char* word = (char*)array_get(text,i);
    list[i] = termlist_create(word);
    min_edit_distance(list[i],dict);
    termlist_print(list[i]);
    termlist_free(list[i]);
  }
  array_free_memory(text);
  array_free_memory(dict);
  free(list);
}

static  void print_array(Array* array){
  unsigned long el_num =  array_size(array);
  
  for(unsigned long i=0;i<el_num;i++){
    char* array_element = (char *)array_get(array, i);
    printf("<%s>\n",array_element); 
  }
}

int main(int argc, char const *argv[]){
  if(argc < 3){
    printf("Usage: app <filename1> <filename2>");
    exit(EXIT_FAILURE);
  }

  test_with_edit_distance(argv[1],argv[2]);

  return (EXIT_SUCCESS);
}