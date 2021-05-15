#pragma once

typedef int (*compare)(void*,void*);

void merge_binary_insertion_sort(void*, size_t, size_t, compare, unsigned long);
