#ifndef MERGE_BINARY_INSERTION_SORT_H
#define MERGE_BINARY_INSERTION_SORT_H
/**
 * Pointer to a function that should be implemented, and represents
 * the order relationship of the objects passed as parameters
 */
typedef int (*compare)(void *, void *);

/**
 * The Merge-BinaryInsertion Sort is a hybrid algorithm that combines Merge Sort and BinaryInsertion Sort. 
 * When the sublist to sort is too short we can advantage of BinaryInsertion Sort that is faster than Merge Sort.
 * In this version of Merge Sort, the sublist of length k or less are sorted using BinaryInsertion Sort
 * and then they are merged using the traditional Merge Sort.
 * k = 0 implies that Merge-BinaryInsertion Sort behaves exactly like the classic Merge Sort,
 * while k >> 0 increases the usage of the BinaryInsertion Sort.
 * 
 * @param void *: the pointer of the vector
 * @param size_t: the number of items of the vector
 * @param size_t: the size of each item of the vector
 * @param compare: the pointer to function, that let to sort the items of the vector
 * @param unsigned long: the value k that represents the length of the smaller sublist to sort with  BinaryInsertion Sort
 */
void merge_binary_insertion_sort(void *, size_t, size_t, compare, unsigned long);
#endif
