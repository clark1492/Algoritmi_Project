#pragma once

typedef struct array Array;

/**
 *  Create a new not sorted array.
 */
Array* array_create();
/**
 * Inserts a new object in the array.
 */
void array_add(Array* , void*);
/**
 *  Returns the object in position i
 */
void* array_get(Array* , unsigned long);
/**
 * Returns the loaded array
 */
void** array_get_internal(Array*);
/**
 * Returns the size of the array
 */
unsigned long array_size(Array*);
/**
 * Frees the memory alloced by array.
 * Note: it does not free the memory of the objects
 *       in the array.
 */ 
void array_free_memory(Array*);
