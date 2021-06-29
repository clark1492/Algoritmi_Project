#ifndef CHAR_ARRAY_H
#define CHAR_ARRAY_H

typedef struct array Array;

/**
 *  Create a new not sorted char array.
 */
Array *array_create();

/**
 * Inserts a new string in the array.
 */
void array_add(Array *, char *);

/**
 *  Returns the string in position i
 */
char *array_get(Array *, unsigned long);

/**
 * Returns the size of the array
 */
unsigned long array_size(Array *);

/**
 * Frees the memory alloced by array.
 * Note: it does not free the memory of the objects
 *       in the array.
 */
void array_free_memory(Array *);
#endif
