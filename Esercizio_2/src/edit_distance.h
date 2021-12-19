#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

/**
 * The recursive version(without memoization) of edit distance. The function calculates the minimum number of operations to commute 
 * the string s2 in s1. The operations are: insert and delete.
 * 
 * @param char *: the first string to compare
 * @param char *: the second string to compare
 * @return
 */
int edit_distance(char *, char *);

/**
 * The recursive and dynamic version (with memoization) of edit distance.
 * It uses dynamic programming that limits recursive calls thanks to the array memoization 
 * 
 * @param char *: the first string to compare
 * @param char *: the second string to compare
 * @return
*/
int edit_distance_dyn(char *, char *);

#endif 