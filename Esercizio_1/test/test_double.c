#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "unity_internals.h"
#include "array.h"

#define UNITY_INCLUDE_DOUBLE

static double* double_new(double n) {
    double* result = (double*) malloc(sizeof(double));
    *result = n;

    return result;
}


static int compare_double(double* obj1, double* obj2) {
    double result;
    result = *obj1 - *obj2;
    if(result == 0)
        return 0;
    else if(result < 0)
        return -1;
    else
        return 1;
    
}

static void delete_test_objects(Array* sa) {
    for(int i=0; i<Array_size(sa); ++i) {
        free(Array_get(sa, i));
    }

    Array_free(sa);
}

static Array* array_create_zero_sized_array() {
    Array* sa = Array_new((ArrayCmp) compare_double);

    return sa;

}

static Array* create_test_one_element_double() {
    Array* sa = Array_new((ArrayCmp) compare_double);
    Array_insert(sa, double_new(2.50));

    return sa;
}

static Array* create_test_notordered_double() {
    Array* sa = Array_new((ArrayCmp) compare_double);
    Array_insert(sa, double_new(2.50));
    Array_insert(sa, double_new(0.001));
    Array_insert(sa, double_new(-1.02));
    Array_insert(sa, double_new(0));

    return sa;
}

static Array* create_test_ascending_double() {
    Array* sa = Array_new((ArrayCmp) compare_double);
    Array_insert(sa, double_new(-1.02));
    Array_insert(sa, double_new(0.001));
    Array_insert(sa, double_new(0));
    Array_insert(sa, double_new(2.50));

    return sa;
}

static Array* create_test_descending_double() {
    Array* sa = Array_new((ArrayCmp) compare_double);
    Array_insert(sa, double_new(2.50));
    Array_insert(sa, double_new(0));
    Array_insert(sa, double_new(0.001));
    Array_insert(sa, double_new(-1.02));

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
    
    Array* sa = create_test_one_element_double();
    InsertionSort(sa);
    TEST_ASSERT_EQUAL(2.50, *(double*) Array_get(sa, 0));
    QuickSort(sa,0,Array_size(sa)-1);
    TEST_ASSERT_EQUAL(2.50, *(double*) Array_get(sa, 0));
    delete_test_objects(sa);
}

static void sorting_ascending_array() {
    
    Array* sa = create_test_ascending_double();
    
    InsertionSort(sa);
    
    TEST_ASSERT_EQUAL(-1.02, *(double*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(0, *(double*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(0.001, *(double*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(2.50, *(double*) Array_get(sa, 3));
    QuickSort(sa,0,Array_size(sa)-1);
    
    TEST_ASSERT_EQUAL(-1.02, *(double*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(0, *(double*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(0.001, *(double*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(2.50, *(double*) Array_get(sa, 3));
    delete_test_objects(sa);

}

static void sorting_descending_array() {
    
    Array* sa = create_test_descending_double();
    Array* da = create_test_descending_double();
    
    InsertionSort(sa);
    
    TEST_ASSERT_EQUAL(-1.02, *(double*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(0, *(double*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(0.001, *(double*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(2.50, *(double*) Array_get(sa, 3));
    QuickSort(da,0,Array_size(da)-1);
    TEST_ASSERT_EQUAL(-1.02, *(double*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(0, *(double*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(0.001, *(double*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(2.50, *(double*) Array_get(sa, 3));
    delete_test_objects(sa);
    delete_test_objects(da);

}

static void sorting_notordered_array() {
  
    Array * sa = create_test_notordered_double();
    Array * da = create_test_notordered_double();
    
    InsertionSort(sa);
    
    TEST_ASSERT_EQUAL(-1.02, *(double*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(0, *(double*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(0.001, *(double*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(2.50, *(double*) Array_get(sa, 3));
    QuickSort(da,0,Array_size(da)-1);
    TEST_ASSERT_EQUAL(-1.02, *(double*) Array_get(sa, 0));
    TEST_ASSERT_EQUAL(0, *(double*) Array_get(sa, 1));
    TEST_ASSERT_EQUAL(0.001, *(double*) Array_get(sa, 2));
    TEST_ASSERT_EQUAL(2.50, *(double*) Array_get(sa, 3));
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