#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "termlist.h"
#include "char_array.h"
#include "edit_distance.h"

#define BUFFER_SIZE 1024

Array *words, *dict;
TermList **array_list;
clock_t start, end;

//Returns the time spent from start to end
static double time_spent_on(long start, long end)
{
  return ((double)(end - start)) / CLOCKS_PER_SEC;
}

//Loads the correctme file in the memory
Array *load_correctme_words(const char *filepath)
{
  char c;
  char word_buffer[BUFFER_SIZE];
  Array *word_list = array_create();
  FILE *fp = fopen(filepath, "r");

  if (fp == NULL)
  {
    fprintf(stderr, "load_correctme_words: unable to open the file\n");
    exit(EXIT_FAILURE);
  }

  memset(word_buffer, 0, BUFFER_SIZE);

  printf("Loading correctme.txt...\n");
  while ((c = (char)fgetc(fp)) != EOF)
  {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
      word_buffer[strlen(word_buffer)] = c;
    else if (c == ' ' || c == '\n')
    {
      word_buffer[strlen(word_buffer)] = '\0';
      array_add(word_list, strdup(word_buffer));
      memset(word_buffer, 0, BUFFER_SIZE); //empty the buffer
    }
  }
  array_add(word_list, strdup(word_buffer));
  fclose(fp);
  printf("File loaded successfully\n\n");

  return word_list;
}

//Loads th edictionary file in the memory
Array *load_dictionary_words(const char *filepath)
{
  FILE *fp = fopen(filepath, "r");
  char word_buffer[BUFFER_SIZE];
  Array *dic_words = array_create();

  if (fp == NULL)
  {
    fprintf(stderr, "load_dictionary_words: unable to open the file\n");
    exit(EXIT_FAILURE);
  }
  printf("Loading dictionary.txt...\n");
  while (fgets(word_buffer, BUFFER_SIZE, fp) != NULL)
  {
    word_buffer[strcspn(word_buffer, "\n")] = '\0';
    array_add(dic_words, strdup(word_buffer));
  }

  fclose(fp);
  printf("File loaded successfully\n\n");

  return dic_words;
}

static TermList *min_edit_distance(char *examed_word, Array *dict)
{
  TermList *list = termlist_create(examed_word);
  for (unsigned long i = 0; i < array_size(dict); i++)
  {
    int dist = edit_distance_dyn(examed_word, (char *)array_get(dict, i));
    if (termlist_size(list) == 0)
    {
      termlist_set_edit(list, dist);
      termlist_add(list, (char *)array_get(dict, i));
    }
    else
    {
      if (dist == termlist_get_edit_distance(list))
        termlist_add(list, (char *)array_get(dict, i));
      else if (dist < termlist_get_edit_distance(list))
      {
        termlist_clear(list);
        termlist_set_edit(list, dist);
        termlist_add(list, (char *)array_get(dict, i));
      }
    }
  }
  return list;
}

static void test_with_edit_distance(const char *filepath_1, const char *filepath_2)
{
  words = load_correctme_words(filepath_1);
  dict = load_dictionary_words(filepath_2);
  array_list = (TermList **)malloc(sizeof(TermList *) * array_size(words));
  printf("\n-------TEXT CORRECTION-------\n\n");

  for (unsigned long i = 0; i < array_size(words); i++)
  {
    char *word_to_examine = (char *)array_get(words, i);
    array_list[i] = min_edit_distance(word_to_examine, dict);
    termlist_print(array_list[i]);
  }
}

// frees the memory from data structures
void shut_off()
{
  for (unsigned long i = 0; i < array_size(words); i++)
    termlist_free(array_list[i]);
  free(array_list);
  array_free_memory(words);
  array_free_memory(dict);
}

int main(int argc, char const *argv[])
{
  if (argc < 3)
  {
    printf("Usage: edit_dtstance_app <correctme.txt> <dictionary.txt>");
    exit(EXIT_FAILURE);
  }
  start = clock();
  test_with_edit_distance(argv[1], argv[2]);
  end = clock();
  printf("The program took %f seconds to complete its job\n", time_spent_on(start, end));
  shut_off();

  return (EXIT_SUCCESS);
}