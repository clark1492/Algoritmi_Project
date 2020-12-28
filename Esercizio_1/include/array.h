#pragma once

typedef struct _Array Array;
typedef int (*ArrayCmp)(void*, void*) ;

/**
 *  Create a new Array.
 *  Parameter: pointer to a function that compares
 *    two objects in the array. The library assumes
 *    that the function returns a value less than 0 if the first 
 *    object is smaller than the first, returns 0
 *    if they are equal, and it returns a value larger than 0 
 *    if the first object is larger than the second.
 */
Array* Array_new(ArrayCmp);

/**
 * Change the compare function of the array.
 */
void ArrayCmp_change(Array* sa, ArrayCmp compare); 

/**
 * Frees the memory alloced by Array_new.
 * Note: it does not free the memory of the objects
 *       in the array.
 */ 
void Array_free(Array* sa);

/**
 * Inserts a new object in the sorted array.
 */
void Array_insert(Array* sa, void* obj);

/**
 *  Returns the object in position i
 */
void* Array_get(Array* sa, int i);

/** Returns the number of elements currently present
 * in the array.
 */
int Array_size(Array* sa);

/** Function that sorting an array 
 * with the insertion sort algorithm.
 */
void InsertionSort(Array* sa);

/** Function that sorting an array 
 * with the quick sort algorithm.
 * Parameters: first and last position of 
 * the array.
 */
void QuickSort(Array* sa, int first, int last);
