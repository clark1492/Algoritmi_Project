#ifndef TERMLIST_H
#define TERMLIST_H

typedef struct term_list TermList;

TermList *termlist_create(char *);
unsigned long termlist_size(TermList *);
void termlist_add(TermList *, char *);
char *termlist_get_word(TermList *);
char *termlist_get_corr(TermList *, unsigned long);
int termlist_get_edit_distance(TermList *);
void termlist_free(TermList *);
void termlist_print(TermList *);
void termlist_clear(TermList *);
void termlist_set_edit(TermList *, int);

#endif