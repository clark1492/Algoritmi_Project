#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "edit_distance.h"

#define MAX_BUFF 1024

//Data elements: six different strings
static char s[7][MAX_BUFF] = {"cassa", "casa", "vinaio", "vino", "tassa", "passato", ""};

/**
 * Test suite for Edit Distance Dynamic function
 */
static void test_same_word()
{
  int e = edit_distance_dyn(s[0], s[0]);
  TEST_ASSERT_EQUAL_INT(0, e);
}

static void test_word_with_char_in_common1()
{
  int e = edit_distance_dyn(s[0], s[1]);
  TEST_ASSERT_EQUAL_INT(1, e);
}

static void test_word_with_char_in_common2()
{
  int e = edit_distance_dyn(s[2], s[3]);
  TEST_ASSERT_EQUAL_INT(2, e);
}

static void test_word_with_char_in_common3()
{
  int e = edit_distance_dyn(s[4], s[5]);
  TEST_ASSERT_EQUAL_INT(4, e);
}

static void test_all_different_char_same_length()
{
  int e = edit_distance_dyn(s[1], s[3]);
  TEST_ASSERT_EQUAL_INT(strlen(s[1]) + strlen(s[3]), e);
}

static void test_all_different_char_different_length()
{
  int e = edit_distance_dyn(s[0], s[3]);
  TEST_ASSERT_EQUAL_INT(strlen(s[0]) + strlen(s[3]), e);
}

static void test_with_empty_string()
{
  int e = edit_distance_dyn(s[0], s[6]);
  TEST_ASSERT_EQUAL_INT(strlen(s[0]), e);
}

static void test_empty_string()
{
  int e = edit_distance_dyn(s[6], s[6]);
  TEST_ASSERT_EQUAL_INT(0, e);
}

int main(void)
{

  //test session
  UNITY_BEGIN();

  RUN_TEST(test_same_word);
  RUN_TEST(test_word_with_char_in_common1);
  RUN_TEST(test_word_with_char_in_common2);
  RUN_TEST(test_word_with_char_in_common3);
  RUN_TEST(test_all_different_char_same_length);
  RUN_TEST(test_all_different_char_different_length);
  RUN_TEST(test_with_empty_string);
  RUN_TEST(test_empty_string);

  return UNITY_END();
}