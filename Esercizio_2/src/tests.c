#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "editdistance.h"

#define MAX_BUFF 1024

static char s [7][MAX_BUFF] = {"cassa","casa","vinaio","vino","tassa","passato",""};

static void test_same_word(){
  unsigned long e = edit_distance_dyn(s[0],s[0]);
  TEST_ASSERT_EQUAL_UINT(0,e);
}

static void test_all_different_char_same_length(){
  unsigned long e = edit_distance_dyn(s[1],s[3]);
  TEST_ASSERT_EQUAL_UINT(strlen(s[1])+strlen(s[3]),e);
}

static void test_all_different_char_different_length(){
  unsigned long e = edit_distance_dyn(s[0],s[3]);
  TEST_ASSERT_EQUAL_UINT(strlen(s[0])+strlen(s[3]),e);
}

static void  test_with_empty_string(){
  unsigned long e = edit_distance_dyn(s[0],s[6]);
  TEST_ASSERT_EQUAL_UINT(strlen(s[0]),e);  
}

static void test_empty_string(){
  unsigned long e = edit_distance_dyn(s[6],s[6]);
  TEST_ASSERT_EQUAL_UINT(0,e);
}

int main(void)
{

  //test session
  UNITY_BEGIN();

  RUN_TEST(test_same_word);
  RUN_TEST(test_all_different_char_same_length);
  RUN_TEST(test_all_different_char_different_length);
  RUN_TEST(test_with_empty_string);
  RUN_TEST(test_empty_string);

  return UNITY_END();
}