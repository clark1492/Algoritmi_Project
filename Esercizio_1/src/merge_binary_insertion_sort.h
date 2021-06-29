#ifndef MERGE_BINARY_INSERTION_SORT_H
#define MERGE_BINARY_INSERTION_SORT_H

typedef int (*compare)(void *, void *);

/**
 * The Merge-BinaryInsertion Sort is a hybrid algorithm that combines Merge Sort and BinaryInsertion Sort. 
 * When the sublist to sort is too short we can advantage of BinaryInsertion Sort that is faster than Merge Sort.
 * In this version of Merge Sort, the sublist of length k or less are sorted using BinaryInsertion Sort
 * and then they are merged using the traditional Merge Sort.
 * k = 0 implies that Merge-BinaryInsertion Sort behaves exactly like the classic Merge Sort,
 * while k >> 0 increases the usage of the BinaryInsertion Sort.
 */
void merge_binary_insertion_sort(void *, size_t, size_t, compare, unsigned long);
#endif
