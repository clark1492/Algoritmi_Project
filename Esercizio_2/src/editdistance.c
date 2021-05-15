#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "editdistance.h"

#define INIT 1
#define NOT_INIT 0
#define MAX_BUFF 1024

static unsigned long rec_edit_distance_dyn(char* s1,char* s2, unsigned long n, unsigned long m,unsigned long** mat, int** i_mat);
static unsigned long min(unsigned long op_1, unsigned long op_2);

unsigned long edit_distance(char* s1, char* s2){
  if(strlen(s1) == 0)
    return strlen(s2);
  if(strlen(s2)== 0)
    return strlen(s1);
  
  char *sub1 = (char*)malloc(sizeof(char)*MAX_BUFF); 
  char *sub2 = (char*)malloc(sizeof(char)*MAX_BUFF);
  strcpy(sub1,s1+1);
  strcpy(sub2,s2+1);
  
  if(s1[0] == s2[0])
    return edit_distance(sub1,sub2);
  return 1 + min(edit_distance(s1,sub2),edit_distance(sub1,s2));
}

unsigned long edit_distance_dyn(char* s1, char*s2){
  printf("-1");
  unsigned long l1 = strlen(s1);
  unsigned long l2 = strlen(s2);
  printf("0");
  unsigned long** mat = (unsigned long**) malloc(sizeof(unsigned long*)*(l1+1));
  int** i_mat = (int**) malloc(sizeof(int*)*(l1+1));
  printf("1");
  unsigned long i,j;

  for(i = 0; i <= l1; i++){
    *mat = (unsigned long*) malloc(sizeof(unsigned long)* (l2+1));
    *i_mat = (int*) malloc(sizeof(int)* (l2+1));
    printf("%lu",i);
    for(j = 0; j <= l2; j++){
      printf("%lu",j);
      if(j == 0 ){
        mat[i][j] = i;
        i_mat[i][j] = INIT;
      }
      if(i == 0){
        mat[i][j] = j;
        i_mat[i][j] = INIT; 
      }
      i_mat[i][j] = NOT_INIT;
      mat[i][j] = 0;
    }
  }
  printf("3");
  return rec_edit_distance_dyn(s1,s2,l1,l2,mat,i_mat);
}

static unsigned long rec_edit_distance_dyn(char* s1,char* s2, unsigned long n, unsigned long m, unsigned long** mat, int** i_mat){
  //se già definito restituisci
  if(i_mat[n][m] != NOT_INIT)
    return mat[n][m];
  
  //se i caratteri sono uguali
  if(s1[n-1] == s2[m-1]){ 
    if(i_mat[n-1][m-1] != NOT_INIT)
      mat[n][m] = mat[n-1][m-1];
    else 
      mat[n][m] = rec_edit_distance_dyn(s1,s2,n-1,m-1,mat,i_mat);
  } 
  
  //se i caratteri sono diverso
  else {
    unsigned long m1,m2;
    
    if(i_mat[n-1][m] != NOT_INIT)   
      m1 = mat[n-1][m];                
    else {
      m1 = rec_edit_distance_dyn(s1, s2, n-1, m, mat, i_mat);
      i_mat[n-1][m] = INIT;
    }      
               
    if(i_mat[n][m-1] != NOT_INIT)               
      m2 = mat[n][m-1];            
    else  {
      m2 = rec_edit_distance_dyn(s1, s2, n, m-1, mat, i_mat);
      i_mat[n][m-1] = INIT;
    }
    mat[n][m] = 1 + min(m1,m2);
  }
  
  i_mat[n][m] = INIT;
  return mat[n][m];
}

static unsigned long min(unsigned long op_1, unsigned long op_2){
  return (op_1 < op_2) ? op_1 : op_2;
}