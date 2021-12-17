#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

/*
 ** The recursive version of edit distance without memoization. The function calculates the minimum number of operations to commute 
 ** the string s2 in s1. The operations are: insert and delete.
 ** 
 ** @param char *: Pointer of the first string.
 ** @param char *: Pointer of the second string.
 ** @returns int: The edit distance between first string and second string passed as parameter, -1 on error.
*/
int edit_distance(char *, char *);

/*
 ** The recursive and dynamic version of edit distance with memoization.
 **
 ** @param char *: Pointer of the first string.
 ** @param char *: Pointer of the second string.
 ** @return int: The edit distance between first string and second string passed as parameter, -1 on error.
*/
int edit_distance_dyn(char *, char *);

#endif 