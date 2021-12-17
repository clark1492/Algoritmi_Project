#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "edit_distance.h"

#define MAX_BUFF 1024

static int rec_edit_distance_dyn(char *s1, char *s2, int l1, int l2, int **matrix);
static int min(int a, int b);
static int **initialize_matrix(int rows, int columns);
static void free_memory(int **matrix, int size);

int edit_distance(char *s1, char *s2)
{
  if (s1 == NULL || s2 == NULL)
    return -1;
  if (strlen(s1) == 0)
    return (int)strlen(s2);
  if (strlen(s2) == 0)
    return (int)strlen(s1);

  char *sub1 = (char *)malloc(sizeof(char) * MAX_BUFF);
  char *sub2 = (char *)malloc(sizeof(char) * MAX_BUFF);
  strcpy(sub1, s1 + 1);
  strcpy(sub2, s2 + 1);

  if (s1[0] == s2[0])
    return edit_distance(sub1, sub2);
  return 1 + min(edit_distance(s1, sub2), edit_distance(sub1, s2));
} 

int edit_distance_dyn(char *s1, char *s2)
{
  if (s1 == NULL || s2 == NULL)
    return -1;
  int l1 = (int)strlen(s1);
  int l2 = (int)strlen(s2);
  int **matrix = initialize_matrix(l1, l2);

  int ret = rec_edit_distance_dyn(s1, s2, l1, l2, matrix);
  free_memory(matrix, l1);
  return ret;
}

/*
 ** Auxiliar function of edit_distance_dyn
 ** 
 ** @param s1: First string
 ** @param s2: Second string
 ** @param l1: Length of the first string
 ** @param l2: Length of the second string 
 ** @param matrix: Matrix for the memoization of the yet calculated values 
 ** @returns int: The edit distance between the two strings passed as parameters
*/
static int rec_edit_distance_dyn(char *s1, char *s2, int l1, int l2, int **matrix)
{
  if (l1 == 0)
    return l2;
  if (l2 == 0)
    return l1;

  //if two characters are not case_sensitive equals
  if (tolower(s1[l1 - 1]) == tolower(s2[l2 - 1]))
  {
    matrix[l1][l2] = rec_edit_distance_dyn(s1, s2, l1 - 1, l2 - 1, matrix);
  }
  //if two characters are not equals
  else
  {
    if (matrix[l1 - 1][l2] == -1)
      matrix[l1 - 1][l2] = rec_edit_distance_dyn(s1, s2, l1 - 1, l2, matrix);
    if (matrix[l1][l2 - 1] == -1)
      matrix[l1][l2 - 1] = rec_edit_distance_dyn(s1, s2, l1, l2 - 1, matrix);

    return matrix[l1][l2] = 1 + min(matrix[l1 - 1][l2], matrix[l1][l2 - 1]);
  }

  return matrix[l1][l2];
}

/*
 ** Method returns lower value
 ** 
 ** @param a 
 ** @param b 
 ** @returns int: The minimum between a and b
*/
static int min(int a, int b)
{
  return a <= b ? a : b;
}

/*
 ** Method initialize the matrix with -1 values
 ** 
 ** @param rows 
 ** @param columns 
 ** @returns int **: A matrix rows x columns initialized with -1 values
*/
static int **initialize_matrix(int rows, int columns)
{
  int **matrix = (int **)malloc(sizeof(int *) * (unsigned long int)(rows + 1));

  for (int i = 0; i <= rows; i++)
    matrix[i] = (int *)malloc(sizeof(int) * (unsigned long int)(columns + 1));
  for (int i = 0; i <= rows; i++)
  {
    for (int j = 0; j <= columns; j++)
      matrix[i][j] = -1;
  }
  return matrix;
}

/*
 ** Method frees the memory occupied by the matrix
 ** 
 ** @param matrix 
 ** @param size 
*/
static void free_memory(int **matrix, int size)
{
  for (int i = 0; i <= size; i++)
    free(matrix[i]);
  free(matrix);
}