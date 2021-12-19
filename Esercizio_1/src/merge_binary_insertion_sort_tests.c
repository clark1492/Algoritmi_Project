#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "merge_binary_insertion_sort.h"

#define K_VALUE 4
/**
 * Test suite for Merge Binary InsertionSort algorithm
 */

//compare functions for integer,string and double
static int compare_int(void *i1_p, void *i2_p);
static int compare_string(void *i1_p, void *i2_p);
static int compare_double(void *i1_p, void *i2_p);

static int compare_int(void *i1_p, void *i2_p)
{
  int *int1_p = (int *)i1_p;
  int *int2_p = (int *)i2_p;

  return ((*int1_p) > (*int2_p)) - ((*int1_p) < (*int2_p));
}

static int compare_string(void *i1_p, void *i2_p)
{
  char **string1_p = (char **)i1_p;
  char **string2_p = (char **)i2_p;
  return strcmp(*string1_p, *string2_p);
}

static int compare_double(void *i1_p, void *i2_p)
{
  double *double1_p = (double *)i1_p;
  double *double2_p = (double *)i2_p;
  return ((*double1_p) > (*double2_p)) - ((*double1_p) < (*double2_p));
}

//Data elements: three not sorted array of integers, strings and floats and three sorted 
static int int_array[] = {19, 56, 25, 17, 100, 58, 72, 1000, 98, 36, 14, 78, 125};
static int ord_int[] = {14, 17, 19, 25, 36, 56, 58, 72, 78, 98, 100, 125, 1000};
static char *string_array[] = {"bbb", "abc", "cba", "hjk", "fg", "xza", "aaa", "123", ":;_"};
static char *ord_string[] = {"123", ":;_", "aaa", "abc", "bbb", "cba", "fg", "hjk", "xza"};
static double double_array[] = {8.5, 1.1, 0.002, -28.01, -6.325, -9, 15, 14, 24.5};
static double ord_double[] = {-28.01, -9.00, -6.325, 0.002, 1.10, 8.5, 14.00, 15.00, 24.50};

static unsigned long nitems_int = sizeof(int_array) / sizeof(int_array[0]);
static unsigned long nitems_string = sizeof(string_array) / sizeof(string_array[0]);
static unsigned long nitems_double = sizeof(double_array) / sizeof(double_array[0]);

static void test_sorting_with_binaryinsertion_sort(void)
{
  merge_binary_insertion_sort(int_array, nitems_int, sizeof(int), compare_int, 0);
  merge_binary_insertion_sort(string_array, nitems_string, sizeof(char *), compare_string, 0);
  merge_binary_insertion_sort(double_array, nitems_double, sizeof(double), compare_double, 0);

  for (unsigned long i = 0; i < nitems_int; i++)
    TEST_ASSERT_EQUAL_INT(ord_int[i], int_array[i]);

  for (unsigned long i = 0; i < nitems_string; i++)
    TEST_ASSERT_EQUAL_STRING(ord_string[i], string_array[i]);

  for (unsigned long i = 0; i < nitems_double; i++)
    TEST_ASSERT_EQUAL(ord_double[i], double_array[i]);
}

static void test_sorting_with_merge_binaryinsertion_sort(void)
{
  merge_binary_insertion_sort(int_array, nitems_int, sizeof(int), compare_int, K_VALUE);
  merge_binary_insertion_sort(string_array, nitems_string, sizeof(char *), compare_string, K_VALUE);
  merge_binary_insertion_sort(double_array, nitems_double, sizeof(double), compare_double, K_VALUE);

  for (unsigned long i = 0; i < nitems_int; i++)
    TEST_ASSERT_EQUAL_INT(ord_int[i], int_array[i]);

  for (unsigned long i = 0; i < nitems_string; i++)
    TEST_ASSERT_EQUAL_STRING(ord_string[i], string_array[i]);

  for (unsigned long i = 0; i < nitems_double; i++)
    TEST_ASSERT_EQUAL(ord_double[i], double_array[i]);
}

static void test_sorting_with_merge_sort(void)
{
  merge_binary_insertion_sort(int_array, nitems_int, sizeof(int), compare_int, nitems_int);
  merge_binary_insertion_sort(string_array, nitems_string, sizeof(char *), compare_string, nitems_string);
  merge_binary_insertion_sort(double_array, nitems_double, sizeof(double), compare_double, nitems_double);

  for (unsigned long i = 0; i < nitems_int; i++)
    TEST_ASSERT_EQUAL_INT(ord_int[i], int_array[i]);

  for (unsigned long i = 0; i < nitems_string; i++)
    TEST_ASSERT_EQUAL_STRING(ord_string[i], string_array[i]);

  for (unsigned long i = 0; i < nitems_double; i++)
    TEST_ASSERT_EQUAL(ord_double[i], double_array[i]);
}

int main(void)
{

  //test session
  UNITY_BEGIN();

  RUN_TEST(test_sorting_with_binaryinsertion_sort);
  RUN_TEST(test_sorting_with_merge_binaryinsertion_sort);
  RUN_TEST(test_sorting_with_merge_sort);

  return UNITY_END();
}