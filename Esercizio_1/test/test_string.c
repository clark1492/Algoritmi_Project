#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "array.h"

#define DIM_BUFF 1024

typedef struct _String String;

struct _String {
    char s [DIM_BUFF] ;
    int length;
};

String* new_string (char* p) {
    String* new = (String*) malloc(sizeof(String));
    for(int i = 0; i < sizeof(p)/sizeof(p[0]); i++)
        new->s[i] = p[i];
    return new;


}



static int compare_strings(char* obj1, char* obj2) {
    return strcmp(obj1,obj2);
}


static void delete_test_objects(Array* sa) {
    for(int j = 0; j < Array_size(sa); ++j) {
            free(Array_get(sa, j));
    }

    Array_free(sa);
}


static Array* array_create_zero_sized_array() {
    Array* sa = Array_new((ArrayCmp) compare_strings);

    return sa;

}

static Array* create_test_one_element_string() {
    Array* sa = Array_new((ArrayCmp) compare_strings);
    Array_insert(sa, new_string("abc"));

    return sa;
}

static Array* create_test_notordered_strings() {
    Array* sa = Array_new((ArrayCmp) compare_strings);
    Array_insert(sa, new_string("abc"));
    Array_insert(sa, new_string("ghi"));
    Array_insert(sa, new_string("lmn"));
    Array_insert(sa, new_string("def"));

    return sa;
}

static Array* create_test_ascending_strings() {
    Array* sa = Array_new((ArrayCmp) compare_strings);
    Array_insert(sa, new_string("abc"));
    Array_insert(sa, new_string("def"));
    Array_insert(sa, new_string("ghi"));
    Array_insert(sa, new_string("lmn"));

    return sa;
}

static Array* create_test_descending_strings() {
    Array* sa = Array_new((ArrayCmp) compare_strings);
    Array_insert(sa, new_string("lmn"));
    Array_insert(sa, new_string("ghi"));
    Array_insert(sa, new_string("def"));
    Array_insert(sa, new_string("abc"));

    return sa;
}



static void sorting_empty_array() {
    Array* sa = array_create_zero_sized_array();
    InsertionSort(sa);
    TEST_ASSERT_EQUAL(0, Array_size(sa));
    QuickSort(sa,0,Array_size(sa)-1);
    TEST_ASSERT_EQUAL(0, Array_size(sa));
    delete_test_objects(sa);
    
}

static void sorting_one_element_array() {
    Array* sa = create_test_one_element_string();
    InsertionSort(sa);
    TEST_ASSERT_EQUAL_STRING("abc", (char*) Array_get(sa, 0));
    QuickSort(sa,0,Array_size(sa)-1);
    TEST_ASSERT_EQUAL_STRING("abc", (char*) Array_get(sa, 0));
    delete_test_objects(sa);
   
}

static void sorting_ascending_array() {
   
    Array* sa = create_test_ascending_strings();
    InsertionSort(sa);
    TEST_ASSERT_EQUAL_STRING("abc", (char*)  Array_get(sa, 0));
    TEST_ASSERT_EQUAL_STRING("def", (char*)  Array_get(sa, 1));
    TEST_ASSERT_EQUAL_STRING("ghi", (char*)  Array_get(sa, 2));
    TEST_ASSERT_EQUAL_STRING("lmn", (char*)  Array_get(sa, 3));
    QuickSort(sa,0,Array_size(sa)-1);
    TEST_ASSERT_EQUAL_STRING("abc", (char*)  Array_get(sa, 0));
    TEST_ASSERT_EQUAL_STRING("def", (char*)  Array_get(sa, 1));
    TEST_ASSERT_EQUAL_STRING("ghi", (char*)  Array_get(sa, 2));
    TEST_ASSERT_EQUAL_STRING("lmn", (char*)  Array_get(sa, 3));
    delete_test_objects(sa);


}

static void sorting_descending_array() {
    Array* sa = create_test_descending_strings();
    Array* da = create_test_descending_strings();
    InsertionSort(sa);
    TEST_ASSERT_EQUAL_STRING("abc", (char*)  Array_get(sa, 0));
    TEST_ASSERT_EQUAL_STRING("def", (char*)  Array_get(sa, 1));
    TEST_ASSERT_EQUAL_STRING("ghi", (char*)  Array_get(sa, 2));
    TEST_ASSERT_EQUAL_STRING("lmn", (char*)  Array_get(sa, 3));
    QuickSort(da,0,Array_size(sa)-1);
    TEST_ASSERT_EQUAL_STRING("abc", (char*)  Array_get(sa, 0));
    TEST_ASSERT_EQUAL_STRING("def", (char*)  Array_get(sa, 1));
    TEST_ASSERT_EQUAL_STRING("ghi", (char*)  Array_get(sa, 2));
    TEST_ASSERT_EQUAL_STRING("lmn", (char*)  Array_get(sa, 3));
    delete_test_objects(sa);
    delete_test_objects(da);

}

static void sorting_notordered_array() {
    Array* sa = create_test_notordered_strings();
    Array* da = create_test_notordered_strings();
    InsertionSort(sa);
    TEST_ASSERT_EQUAL_STRING("abc", (char*)  Array_get(sa, 0));
    TEST_ASSERT_EQUAL_STRING("def", (char*)  Array_get(sa, 1));
    TEST_ASSERT_EQUAL_STRING("ghi", (char*)  Array_get(sa, 2));
    TEST_ASSERT_EQUAL_STRING("lmn", (char*)  Array_get(sa, 3));
    QuickSort(da,0,Array_size(sa)-1);
    TEST_ASSERT_EQUAL_STRING("abc", (char*)  Array_get(sa, 0));
    TEST_ASSERT_EQUAL_STRING("def", (char*)  Array_get(sa, 1));
    TEST_ASSERT_EQUAL_STRING("ghi", (char*)  Array_get(sa, 2));
    TEST_ASSERT_EQUAL_STRING("lmn", (char*)  Array_get(sa, 3));
    delete_test_objects(sa);
    delete_test_objects(da);

}

int main() {
    UNITY_BEGIN();
    
    
    RUN_TEST(sorting_empty_array);
    RUN_TEST(sorting_one_element_array);
    RUN_TEST(sorting_ascending_array);
    RUN_TEST(sorting_descending_array);
    RUN_TEST(sorting_notordered_array);

    UNITY_END();
}
