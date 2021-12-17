#ifndef MERGE_BINARY_INSERTION_SORT_H
#define MERGE_BINARY_INSERTION_SORT_H
/*
** Function pointer that should be implemented, it represents the order relationship of the elements of the array
*/
typedef int (*compare)(void *, void *);

/*
 ** The Merge-BinaryInsertion Sort is a hybrid algorithm that combines Merge Sort and BinaryInsertion Sort. 
 ** When the sublist to sort is too short we can advantage of BinaryInsertion Sort that is faster than Merge Sort.
 ** In this version of Merge Sort, the sublist of length k or less are sorted using BinaryInsertion Sort
 ** and then they are merged using the traditional Merge Sort.
 ** k = 0 implies that Merge-BinaryInsertion Sort behaves exactly like the classic Merge Sort,
 ** while k >> 0 increases the usage of the BinaryInsertion Sort.
 ** 
 ** @param void * : a pointer of the array that will be sorted
 ** @param size_t : the number of the elements of the array
 ** @param size_t : the size of each element of the array
 ** @param compare : the pointer to a function that represents the order relationship of the elements of the array
 ** @param unsigned long : the length of the sublist from which to start using BinaryInsertion Sort
 */
void merge_binary_insertion_sort(void *, size_t, size_t, compare, unsigned long);

#endif