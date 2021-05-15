#pragma once 

typedef struct list_term ListTerm;

ListTerm* create_ListTerm(char*);
void print_list(ListTerm*);
int is_empty(ListTerm*);
void add_term(ListTerm*, char*);
char* get_word(ListTerm*);
char* get_correction(ListTerm*, unsigned long);
void free_list(ListTerm*);