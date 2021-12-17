#ifndef TERMLIST_H
#define TERMLIST_H
/*
 ** A struct with a string to correct and an array of strings that represent the corrections 
 ** of the first one, with their edit distance.
*/
typedef struct term_list TermList;

/*
 ** Create a new struct termlist 
 **
 ** @param char *: The string to correct
 ** @returns Termlist *: A pointer to the new struct
*/
TermList *termlist_create(char *);

/*
 ** Returns the size of the corrections array 
 **
 ** @param Termlist *: The pointer to the struct Termlist
 ** @returns unsigned long: The size of the internal array
*/
unsigned long termlist_size(TermList *);

/*
 ** Add a string to the internal array
 **
 ** @param Termlist *: The pointer to the struct Termlist
 ** @param char *: The string to add
*/
void termlist_add(TermList *, char *);

/*
 ** Returns the string to correct
 **
 ** @param Termlist *: The pointer to the struct Termlist
 ** @returns char *: The string to correct
*/
char *termlist_get_word(TermList *);

/*
 ** Returns the correction string in the position passed as parameter
 ** 
 **
 ** @param Termlist *: The pointer to the struct Termlist
 ** @param unsigned long: The index of the internal array
 ** @returns char *: The string in the position passed as parameter 
*/
char *termlist_get_corr(TermList *, unsigned long);

/*
 ** Returns the edit distance between the string to correct and 
 ** the strings in the internal array
 **
 ** @param Termlist *: The pointer to the struct Termlist
 ** @returns unsigned long: The size of the internal array
*/
int termlist_get_edit_distance(TermList *);

/*
 ** Frees the memory allocated by termlist
 **
 ** @param Termlist *: The pointer to the struct Termlist
*/
void termlist_free(TermList *);

/*
 ** Print the string to correct and all the strings in the internal array
 ** and their edit distance  
 **
 ** @param Termlist *: The pointer to the struct Termlist
*/
void termlist_print(TermList *);

/*
 ** Clear all the strings in the internal array
 **
 ** @param Termlist *: The pointer to the struct Termlist
*/
void termlist_clear(TermList *);
#endif