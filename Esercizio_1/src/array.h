#ifndef ARRAY_H
#define ARRAY_H

typedef struct array Array;

/*
 ** Create a new not sorted array.
 ** 
 ** @returns Array *: A pointer to the struct Array
 */
Array *array_create();

/*
 ** Appends a new object in the array.
 ** 
 ** @param Array *: A pointer to the struct Array
 ** @param void *: A pointer to the object to append in the array
 */
void array_add(Array *, void *);

/*
 ** Returns the object in position i
 **
 ** @param Array *: A pointer to the struct Array
 ** @param unsigned long: The index of the array
 ** @returns void *: The object in the position i
 */
void *array_get(Array *, unsigned long);

/*
 ** Returns the internal array
 **
 ** @param Array *: A pointer to the struct Array
 ** @returns void **: The pointer of the internal array
 */
void **array_get_internal(Array *);

/*
 ** Returns the size of the array
 ** 
 ** @param Array *: A pointer to the struct Array
 ** @returns unsigned long: The size of the array
 */
unsigned long array_size(Array *);

/*
 ** Frees the memory allocated by array.
 ** Note: it does not free the memory of the objects
 **       in the array.
 **
 ** @param Array *: A pointer to the struct Array
 */
void array_free_memory(Array *);
#endif
