#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "merge_binary_insertion_sort.h"

#define K_VALUE 2
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

//Data elements that are initialized before each test
static int int_array[] = {19, 56, 25, 17, 100, 58, 72, 1000, 98, 36, 14, 78, 125};
static char *string_array[] = {"bbb", "abc", "cba", "hjk", "fg", "xza", "aaa", "123", ":;_"};
static double double_array[] = {8.5, 1.1, 0.002, -28.01, -6.325, -9, 15, 14, 24.5};

static void test_sorting_four_elem_int_array(void)
{
  int ord_int[] = {14, 17, 19, 25, 36, 56, 58, 72, 78, 98, 100, 125, 1000};
  unsigned long nitems = sizeof(int_array) / sizeof(int_array[0]);

  merge_binary_insertion_sort(int_array, nitems, sizeof(int), compare_int, K_VALUE);

  for (unsigned long i = 0; i < nitems; i++)
    TEST_ASSERT_EQUAL_INT(ord_int[i], int_array[i]);
}

static void test_sorting_four_elem_string_array(void)
{

  char *ord_string[] = {"123", ":;_", "aaa", "abc", "bbb", "cba", "fg", "hjk", "xza"};
  unsigned long nitems = sizeof(string_array) / sizeof(string_array[0]);

  merge_binary_insertion_sort(string_array, nitems, sizeof(char *), compare_string, K_VALUE);

  for (unsigned long i = 0; i < 4; i++)
    TEST_ASSERT_EQUAL_STRING(ord_string[i], string_array[i]);
}

static void test_sorting_four_elem_double_array(void)
{
  double ord_double[] = {-28.01, -9.00, -6.325, 0.002, 1.10, 8.5, 14.00, 15.00, 24.50};
  unsigned long nitems = sizeof(double_array) / sizeof(double_array[0]);

  merge_binary_insertion_sort(double_array, nitems, sizeof(double), compare_double, K_VALUE);

  for (unsigned long i = 0; i < nitems; i++)
    TEST_ASSERT_EQUAL(ord_double[i], double_array[i]);
}

int main(void)
{

  //test session
  UNITY_BEGIN();

  RUN_TEST(test_sorting_four_elem_int_array);
  RUN_TEST(test_sorting_four_elem_double_array);
  RUN_TEST(test_sorting_four_elem_string_array);

  return UNITY_END();
}