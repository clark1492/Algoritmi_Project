#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "array.h"

#define STR_LENGTH 256


static int* int_new(int n) {
    int* result = (int*) malloc(sizeof(int));
    *result = n;

    return result;
}

static int compare_ints(int* obj1, int* obj2) {
    return *obj1 - *obj2;
}

static void delete_test_objects(Array* sa) {
    for(int i=0; i<Array_size(sa); ++i) {
        free(Array_get(sa, i));
    }

    Array_free(sa);
}

static Array* array_create_zero_sized_array() {
    Array* sa = Array_new((ArrayCmp) compare_ints);

    return sa;

}

static Array* create_test_one_element_int() {
    Array* sa = Array_new((ArrayCmp) compare_ints);
    Array_insert(sa, int_new(1));

    return sa;
}

static Array* create_test_notordered_ints() {
    Array* sa = Array_new((ArrayCmp) compare_ints);
    Array_insert(sa, int_new(8));
    Array_insert(sa, int_new(5));
    Array_insert(sa, int_new(1));
    Array_insert(sa, int_new(11));

    return sa;
}


static Array* create_test_ascending_ints() {
    Array* sa = Array_new((ArrayCmp) compare_ints);
    Array_insert(sa, int_new(1));
    Array_insert(sa, int_new(5));
    Array_insert(sa, int_new(8));
    Array_insert(sa, int_new(11));

    return sa;
}

static Array* create_test_descending_ints() {
    Array* sa = Array_new((ArrayCmp) compare_ints);
    Array_insert(sa, int_new(11));
    Array_insert(sa, int_new(8));
    Array_insert(sa, int_new(5));
    Array_insert(sa, int_new(1));

    return sa;
}
static void sorting_empty_array() {
    Array* sa = array_create_zero_sized_array();
    InsertionSort(sa);
    TEST_ASSERT_EQUAL(0, Array_size(sa));
    QuickSort(sa,0,Array_size(sa)-1);
    TEST_ASSERT_EQUAL(0, Array_size(sa));
    Array_free(sa);
}

static void sorting_one_element_array() {
    Array* sa = create_test_one_element_int();
    InsertionSort(sa);
    TEST_ASSERT_EQUAL(1, *(int*) Array_get(sa, 0));
    QuickSort(sa,0,Array_size(sa)-1);
    TEST_ASSERT_EQUAL(1, *(int*) Array_get(sa, 0));
    delete_test_objects(sa);
}

static void sorting_ascending_array() {
    
    Array* sa = create_test_ascending_ints();
    InsertionSort(sa);
    TEST_ASSERT_EQUAL(1, *(int*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(5, *(int*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(8, *(int*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(11, *(int*) Array_get(sa, 3));
    QuickSort(sa,0,Array_size(sa)-1);
    TEST_ASSERT_EQUAL(1, *(int*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(5, *(int*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(8, *(int*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(11, *(int*) Array_get(sa, 3));
    delete_test_objects(sa);

}

static void sorting_descending_array() {
    Array* sa = create_test_descending_ints();
    Array* da = create_test_descending_ints();
    InsertionSort(sa);
    TEST_ASSERT_EQUAL(1, *(int*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(5, *(int*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(8, *(int*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(11, *(int*) Array_get(sa, 3));
    QuickSort(da,0,Array_size(da)-1);
    TEST_ASSERT_EQUAL(1, *(int*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(5, *(int*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(8, *(int*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(11, *(int*) Array_get(sa, 3));
    delete_test_objects(sa);
    delete_test_objects(da);
  
}

static void sorting_notordered_array() {
    Array* sa = create_test_notordered_ints();
    Array* da = create_test_notordered_ints();
    InsertionSort(sa);
    TEST_ASSERT_EQUAL(1, *(int*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(5, *(int*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(8, *(int*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(11, *(int*) Array_get(sa, 3));
    QuickSort(da,0,Array_size(da)-1);
    TEST_ASSERT_EQUAL(1, *(int*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(5, *(int*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(8, *(int*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(11, *(int*) Array_get(sa, 3));
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