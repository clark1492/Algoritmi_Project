#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "merge_binary_insertion_sort.h"
#include "array.h"

#define MAX_BUF_LEN 1024

clock_t start, end;

typedef struct record
{
  int id;
  char *string_field;
  int integer_field;
  double double_field;
} Record;

/** Handler that kills the process
 * if it lasts longer than ten minutes
 */
static void sigalarm_handler(int signal)
{
  printf("Time expired.Got signal #%d: %s\n", signal, strsignal(signal));
  kill(getpid(), SIGKILL);
}

/**
 * It returns the time spent from start to end
 */
static double time_spent_on(long start, long end)
{
  return ((double)(end - start)) / CLOCKS_PER_SEC;
}

/**
 * It takes as input two pointers of pointers to struct record.
 * It returns zero if the two string fields of the records are equal,
 * a value greater than zero if the string field of
 * the first record is greater than the second one's string field,
 * or a value less than zero otherwise
 */
static int compare_string_field(void *elem1, void *elem2)
{
  if (elem1 == NULL)
  {
    fprintf(stderr, "compare_first_field: elem1 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  if (elem2 == NULL)
  {
    fprintf(stderr, "compare_first_field: elem2 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  Record **rec1 = (Record **)(elem1);
  Record **rec2 = (Record **)(elem2);
  return strcmp((*rec1)->string_field, (*rec2)->string_field);
}

/**
 * It takes as input two pointers of pointers to struct record.
 * It returns zero if the two integer fields of the records are equal,
 * a value greater than zero if the integer field of
 * the first record is greater than the second one's integer field,
 * or a value less than zero otherwise
 */
static int compare_int_field(void *elem1, void *elem2)
{
  if (elem1 == NULL)
  {
    fprintf(stderr, "compare_first_field: elem1 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  if (elem2 == NULL)
  {
    fprintf(stderr, "compare_first_field: elem2 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  Record **rec1 = (Record **)elem1;
  Record **rec2 = (Record **)elem2;

  return ((*rec1)->integer_field > (*rec2)->integer_field) - ((*rec1)->integer_field < (*rec2)->integer_field);
}

/**
 * It takes as input two pointers of pointers to struct record.
 * It returns zero if the two double fields of the records are equal,
 * a value greater than zero if the double field of
 * the first record is greater than the second one's double field,
 * or a value less than zero otherwise
 */
static int compare_double_field(void *elem1, void *elem2)
{
  if (elem1 == NULL)
  {
    fprintf(stderr, "compare_first_field: elem1 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  if (elem2 == NULL)
  {
    fprintf(stderr, "compare_first_field: elem2 parameter is a null pointer\n");
    exit(EXIT_FAILURE);
  }
  Record **rec1 = (Record **)elem1;
  Record **rec2 = (Record **)elem2;

  return ((*rec1)->double_field > (*rec2)->double_field) - ((*rec1)->double_field < (*rec2)->double_field);
}

static void print_usage()
{
  printf("sorting_app <file_csv_path> < 1 | 2 | 3 > < K_VALUE >\n");
  printf("    1: sort according to the field1 ascending order\n");
  printf("    2: sort according to the field2 ascending order\n");
  printf("    3: sort according to the field3 ascending order\n");
  printf("    K_VALUE: the length of the sublist that are sorted using BinaryInsertion Sort\n");
}

static void load_array(const char *file_name, Array *base)
{
  int rows = 0;
  char buffer[MAX_BUF_LEN];
  FILE *fp;
  printf("\nLoading data from file...\n");
  fp = fopen(file_name, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "main: unable to open the file\n");
    exit(EXIT_FAILURE);
  }
  while (fgets(buffer, MAX_BUF_LEN, fp) != NULL)
  {
    Record *rec = malloc(sizeof(Record));
    if (rec == NULL)
    {
      fprintf(stderr, "main: unable to allocate memory for the read record\n");
      exit(EXIT_FAILURE);
    }
    char *id_field_in_read_line_p = strtok(buffer, ",");
    char *string_field_in_read_line_p = strtok(NULL, ",");
    char *integer_field_in_read_line_p = strtok(NULL, ",");
    char *double_field_in_read_line_p = strtok(NULL, ",");
    rec->string_field = malloc(sizeof(char) * strlen(string_field_in_read_line_p) + 1);
    if (rec->string_field == NULL)
    {
      fprintf(stderr, "main: unable to allocate memory for the string field of the read record\n");
      exit(EXIT_FAILURE);
    }
    strcpy(rec->string_field, string_field_in_read_line_p);
    rec->id = atoi(id_field_in_read_line_p);
    rec->integer_field = atoi(integer_field_in_read_line_p);
    rec->double_field = atof(double_field_in_read_line_p);
    array_add(base, (void *)rec);
    rows++;
  }
  fclose(fp);
  printf("%d file rows has been successfully loaded.\n", rows);
}

static void print_array(Array *array)
{
  if (array == NULL)
  {
    printf("Array cannot be null");
    exit(EXIT_FAILURE);
  }
  if (array_get_internal(array) == NULL)
  {
    printf("Internal array cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if (array_size(array) == 0)
  {
    printf("Array cannot be empty");
    exit(EXIT_FAILURE);
  }
  printf("\nWriting the sorted array in output/sorted_records.csv...\n");
  FILE *file = fopen("output/sorted_records.csv", "w");
  if (file == NULL)
  {
    printf("Unable to open the file");
    exit(EXIT_FAILURE);
  }
  for (unsigned long i = 0; i < array_size(array); i++)
    fprintf(file, "%d,%s,%d,%f\n", ((Record *)array_get(array, i))->id, ((Record *)array_get(array, i))->string_field, ((Record *)array_get(array, i))->integer_field, ((Record *)array_get(array, i))->double_field);
  fclose(file);
  printf("File has been successfully written\n");
}

static void free_data(Array *array)
{
  for (unsigned long i = 0; i < array_size(array); ++i)
  {
    struct record *rec = array_get(array, i);
    free(rec->string_field);
    free(rec);
  }
  array_free_memory(array);
}

static void test_with_merge_binary_insertion_sort(const char *filename, int (*compare)(void *, void *), unsigned long k_value)
{
  Array *array;
  array = array_create();
  load_array(filename, array);
  printf("\nSorting..... \n");
  start = clock();
  merge_binary_insertion_sort(array_get_internal(array), array_size(array), sizeof(Record *), compare, k_value);
  end = clock();
  printf("Time spent to sort: %f\n", time_spent_on(start, end));
  print_array(array);
  free_data(array);
}

int main(int argc, char const *argv[])
{
  unsigned long k_value;
  int sorting_choice;

  sorting_choice = atoi(argv[2]);
  k_value = strtoul(argv[3], NULL, 0);
  if (argc != 4 || sorting_choice < 0 || sorting_choice > 3 || k_value >= 20000000)
  {
    printf("Parameters error\n");
    print_usage();
    exit(EXIT_FAILURE);
  }

  signal(SIGALRM, sigalarm_handler);

  alarm(600);

  if (sorting_choice == 1)
  {
    printf("\nSorting the array with Merge-BinaryInsertion Sort according to the string field ascending order with k = %lu\n", k_value);
    test_with_merge_binary_insertion_sort(argv[1], compare_string_field, k_value);
  }
  else if (sorting_choice == 2)
  {
    printf("\nSorting the array with Merge-BinaryInsertion Sort according to the integer field ascending order with k = %lu\n", k_value);
    test_with_merge_binary_insertion_sort(argv[1], compare_int_field, k_value);
  }

  else
  {
    printf("\nSorting the array with Merge-BinaryInsertion Sort according to the double field ascending order with k = %lu\n", k_value);
    test_with_merge_binary_insertion_sort(argv[1], compare_double_field, k_value);
  }

  return (EXIT_SUCCESS);
}