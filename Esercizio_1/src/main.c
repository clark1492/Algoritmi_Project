#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "merge_binary_insertion_sort.h"
#include "array.h"

#define MAX_BUF_LEN 1024

#ifndef K_VALUE 
#define K_VALUE 10
#endif

struct record{
  int id;
  char* string_field;
  int int_field;
  double double_field;
};


static void set_handler(int signal, void (*func)(int)) {
  struct sigaction sa;
  sigset_t mask;
  bzero(&sa, sizeof(sa));
  sigemptyset(&mask);
  sa.sa_handler = func;
  sa.sa_mask = mask;
  sa.sa_flags = 0;
  sigaction(signal, &sa, NULL);
}

/** Handler that kill the process
 * if it lasts longer than ten minutes
 */ 
static void sigalarm_handler(int signal){
 
  printf("Time expired.Got signal #%d: %s\n", signal, strsignal(signal));
  kill(getpid(),SIGKILL);
}

/** Defines the type of records read from file
 */

/**Functions to compare each field of the records 
 */
static int compare_string_field(void* elem1, void* elem2) {
  if(elem1 == NULL){
    fprintf(stderr,"compare_first_field: rec1 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  if(elem2 == NULL){
    fprintf(stderr,"compare_first_field: rec2 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  struct record** rec1 = (struct record**) elem1;
  struct record** rec2 = (struct record**) elem2;
  return strcmp((*rec1)->string_field,(*rec2)->string_field);
}

static int compare_int_field(void* elem1, void* elem2) {
  if(elem1 == NULL){
    fprintf(stderr,"compare_first_field: rec1 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  if(elem2 == NULL){
    fprintf(stderr,"compare_first_field: rec2 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  struct record **rec1 = (struct record**) elem1;
  struct record **rec2 = (struct record**) elem2;
  
  return ((*rec1)->int_field-(*rec2)->int_field);
}

static int compare_double_field(void* elem1, void* elem2) {
  if(elem1 == NULL){
    fprintf(stderr,"compare_first_field: rec1 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  if(elem2 == NULL){
    fprintf(stderr,"compare_first_field: rec2 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  struct record **rec1 = (struct record**) elem1;
  struct record **rec2 = (struct record**) elem2;
  
  double result = (*rec1)->double_field-(*rec2)->double_field;
  
  if(result == 0)
    return 0;
  if(result > 0)
    return 1;
  return -1;
}

static void print_usage() {
  printf("sorting_app <filename>\n");
}

static void load_array(const char* file_name, Array* base){
  char *read_line_p;
  char buffer[MAX_BUF_LEN];
  int buf_size = MAX_BUF_LEN;
  FILE *fp;
  printf("\nLoading data from file...\n");
  fp = fopen(file_name,"r");
  if(fp == NULL){
    fprintf(stderr,"main: unable to open the file\n");
    exit(EXIT_FAILURE);
  }
  while(fgets(buffer,buf_size,fp) != NULL){  
    read_line_p = malloc((strlen(buffer)+1)*sizeof(char));
    if(read_line_p == NULL){
      fprintf(stderr,"main: unable to allocate memory for the read line\n");
      exit(EXIT_FAILURE);
    }   
    strcpy(read_line_p,buffer);   
    char *id_field_in_read_line_p =strtok(read_line_p,",");
    char *string_field_in_read_line_p = strtok(NULL,",");
    char *integer_field_in_read_line_p = strtok(NULL,",");
    char *double_field_in_read_line_p = strtok(NULL,",");  
    char *string_field = malloc((strlen(string_field_in_read_line_p)+1)*sizeof(char));
    if(string_field == NULL){
      fprintf(stderr,"main: unable to allocate memory for the string field of the read record\n");
      exit(EXIT_FAILURE);
    }  
    strcpy(string_field,string_field_in_read_line_p);
    int id_field = atoi(id_field_in_read_line_p);
    int integer_field = atoi(integer_field_in_read_line_p);
    double double_field = atof(double_field_in_read_line_p);  
    struct record* temp = malloc(sizeof(struct record));
    if(string_field == NULL){
      fprintf(stderr,"main: unable to allocate memory for the read record\n");
      exit(EXIT_FAILURE);
    }   
    temp->id = id_field;
    temp->string_field = string_field;
    temp->int_field = integer_field;
    temp->double_field = double_field;
    array_add(base,temp);
    free(read_line_p);
  }
  fclose(fp);
  printf("\nData loaded\n");
}

static void print_array(Array* array) {
  unsigned long el_num = array_size(array);
  struct record* rec;
  printf("\nORDERED ARRAY OF RECORDS\n");
  
  for(unsigned long i=0; i<el_num; i++) {
    rec = (struct record*)array_get(array, i);
    printf("id: %10d\t\tstring_field: %20s\t\tint_field: %10d\t\tdouble_field: %15f\n", rec->id, rec->string_field, rec->int_field, rec->double_field);
  }
}

void free_data(Array* array) {
  for(unsigned long i=0; i<array_size(array); ++i) {
    struct record* rec = array_get(array, i);
    free(rec->string_field);
    free(rec);
  }
  array_free_memory(array);
}

static void test_with_merge_binary_insertion_sort(const char* filename, int (*compare)(void*,void*)) {
  Array* sa = array_create();
  load_array(filename, sa);
  merge_binary_insertion_sort(array_get_internal(sa),array_size(sa), sizeof(struct record*), compare, K_VALUE);
  printf("Ordinato.\n");
  print_array(sa);
  free_data(sa);
}

int main(int argc, char const *argv[])
{
  if(argc != 2) {
    printf("Parameters error\n");
    print_usage();
    exit(EXIT_FAILURE);
  }
  
  set_handler(SIGALRM, &sigalarm_handler);
  
	alarm(600);
  printf("\nTest sort string field of the array:\n");
  test_with_merge_binary_insertion_sort(argv[1], compare_string_field);
  printf("\nTest sort int field of the array:\n");
  test_with_merge_binary_insertion_sort(argv[1], compare_int_field);
  printf("\nTest sort double field of the array:\n");
  test_with_merge_binary_insertion_sort(argv[1], compare_double_field);
  
  return (EXIT_SUCCESS);
}