#ifndef CHAR_ARRAY_H
#define CHAR_ARRAY_H

typedef struct array Array;

/*
 **  Create a new not sorted char array.
 **
 **@param Array *: A pointer to the struct Array
 */
Array *array_create();

/*
 ** Inserts a new string in the array.
 **
 ** @param Array *: A pointer to the struct Array
 ** @param char *: A pointer to the string to add in the array
 */
void array_add(Array *, char *);

/*
 ** Returns the string in position i
 **
 ** @param Array *: A pointer to the struct Array
 ** @param unsigned long: The index of the array
 ** @returns char *: The string in the position i
 */
char *array_get(Array *, unsigned long);

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
