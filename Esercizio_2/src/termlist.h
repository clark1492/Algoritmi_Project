#ifndef TERMLIST_H
#define TERMLIST_H

typedef struct term_list TermList;

/**
 * Creates and returns the struct Termlist of the string passed as parameter
 * 
 * @param char *: the reference string  
 * @return  
 */
TermList *termlist_create(char *);

/**
 * Returns the number of the corrections of the reference string
 * 
 * @param TermList *: pointer to the struct Termlist
 * @return 
 */
unsigned long termlist_size(TermList *);

/**
 * Adds a string to the corrections array
 * 
 * @param TermList *: pointer to the struct Termlist
 * @param char *: the string to add
 */
void termlist_add(TermList *, char *);

/**
 * Returns the reference string of Termlist
 * 
 * @param TermList *: pointer to the struct Termlist
 * @return 
 */
char *termlist_get_word(TermList *);

/**
 * Returns a string in the corrections array at the position passed as parameter
 * 
 * @param TermList *: pointer to the struct Termlist
 * @param unsigned long: the index of the array 
 * @return 
 */
char *termlist_get_corr(TermList *, unsigned long);

/**
 * Returns the edit distance between the reference string and the correction strings
 *
 * @param TermList *: pointer to the struct Termlist 
 * @return
 */
int termlist_get_edit_distance(TermList *);

/**
 * Free the memory by the struct TermList
 *
 * @param TermList *: pointer to the struct Termlist 
 */
void termlist_free(TermList *);

/**
 * Prints the content of the TermList
 *
 * @param TermList *: pointer to the struct Termlist 
 */
void termlist_print(TermList *);

#endif