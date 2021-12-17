#pragma once 

typedef struct term_list TermList;

TermList* termlist_create(char*);
unsigned long termlist_size(TermList*);
void termlist_add(TermList*, char*);
char* termlist_get_word(TermList*);
char* termlist_get_corr(TermList*, unsigned long);
void termlist_free(TermList*);
void termlist_print(TermList*);