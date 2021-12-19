#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

/**
 * A string array data structure of not sorted elements
 * 
 */
typedef struct string_array Array;

/**
 *  Create a new not sorted char array.
 */
Array *array_create();

/**
 * Inserts a new string in the array.
 * 
 * @param Array *: the pointer of the struct Array
 * @param char *: the string to append
 */
void array_add(Array *, char *);

/**
 * Returns the string in position i
 * 
 * @param Array *: the pointer of the struct Array
 * @param unsigned long: the index of the string in the array
 * @return
 */
char *array_get(Array *, unsigned long);

/**
 * Returns the size of the array
 * 
 * @param Array *: the pointer of the struct Array
 * @return
 */
unsigned long array_size(Array *);

/**
 * Frees the memory alloced by array.
 * Note: it does not free the memory of the objects
 *       in the array.
 */
void array_free_memory(Array *);
#endif