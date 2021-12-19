#ifndef ARRAY_H
#define ARRAY_H

/**
 * An Array data structure of not sorted elements
 * 
 */
typedef struct array Array;

/**
 * Creates the struct Array.
 */
Array *array_create();

/**
 * Appends a new object in the array.
 * 
 * @param Array *: the pointer of the struct Array
 * @param void *: the object to append
 */
void array_add(Array *, void *);

/**
 * Returns the object in position i
 * 
 * @param Array *: the pointer of the struct Array
 * @param unsigned long: the index of the object in the array
 * @return 
 */
void *array_get(Array *, unsigned long);

/**
 * Returns the array in the struct
 * 
 * @param Array *: the pointer of the struct Array
 * @return
 */
void **array_get_internal(Array *);

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