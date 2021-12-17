#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H 

/**
 * The recursive version of edit distance. The function calculates the minimum number of operations to commute 
 * the string s2 in s1. The operations are: insert and delete.
 */
 int edit_distance(char* , char*);

 /**
  * The recursive and dynamic version of edit distance.
  */
 int edit_distance_dyn(char* , char*); 
 
 #endif //EDIT_DISTANCE_H