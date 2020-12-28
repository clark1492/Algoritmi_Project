#include <stdlib.h>
#include "array.h"

#define INITIAL_CAPACITY 2

struct _Array {
    void** array;
    int capacity;
    int size;
    ArrayCmp compare;
};


Array* Array_new(ArrayCmp compare) {
    Array* result = (Array*) malloc(sizeof(Array));
    result->capacity = INITIAL_CAPACITY;
    result->array = (void**) malloc(sizeof(void*) * result->capacity);
    result->size = 0;
    result->compare = compare;

    return result;
}

void ArrayCmp_change(Array* sa, ArrayCmp compare) {
    sa->compare = compare;
}

void Array_free(Array* sa) {
    free(sa->array);
    free(sa);
}

void Array_resize(Array* sa, size_t memsize) {
    sa->capacity = memsize;
    sa->array = (void**) realloc(sa->array, sa->capacity * sizeof(void*));
}

void Array_insert(Array* sa, void* obj) {
    if(sa->capacity == sa->size) {
        Array_resize(sa, sa->capacity * 2);
    }
    sa->array[sa->size] = obj;
    sa->size++;
}

void* Array_get(Array* sa, int i) {
    return sa->array[i];
}

int Array_size(Array* sa) {
    return sa->size;
}


void InsertionSort(Array* sa) {
    void* temp;
    int j;
    temp = malloc(sizeof(int));
    for(int i = 1; i < Array_size(sa); i++) {
        j = i;
        while (j > 0 && sa->compare(sa->array[j-1],sa->array[j]) > 0)  {
            temp = sa->array[j];
            sa->array[j]= sa->array[j-1];
            sa->array[j-1] = temp;
            j = j-1;
        }
    }

}

void QuickSort(Array* sa, int first, int last) {
    int p,j,i;
    void* temp;
    if(first < last) {
        p = first;
        i = first;
        j = last;

        while(i < j) {
            while(sa->compare(sa->array[i],sa->array[p]) <= 0 && i < last)
                i++;
            while(sa->compare(sa->array[j],sa->array[p]) > 0)
                j--;
            if(i < j) {
                temp = sa->array[i];
                sa->array[i] = sa->array[j];
                sa->array[j] = temp;
            }
        }
        temp = sa->array[p];
        sa->array[p] = sa->array[j];
        sa->array[j] = temp;
        QuickSort(sa,first,j-1);
        QuickSort(sa,j+1,last);
    }
}