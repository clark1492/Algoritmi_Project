#include "array.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

#define ERROR_EXIT_CODE 1

/** Handler that kill the process
 * if it lasts longer than ten minutes
 */ 
void sig_handler(int signum){
 
  printf("Ten minutes expired\n");
  kill(getpid(),SIGKILL);
}

/** Defines the type of records read from file
 */
typedef struct {
    int id;
    char* field_one;
    int field_two;
    double field_three;
} Record;

/**Functions to compare each field of the records 
 */
int compare_first_field(Record* rec1, Record* rec2) {
    return strcmp(rec1->field_one, rec2->field_one);
}

int compare_second_field(Record* rec1, Record* rec2) {
    return rec1->field_two - rec2->field_two;
}

int compare_third_field(Record* rec1, Record* rec2) {
    double result;
    result = rec1->field_three - rec2->field_three;
    if(result == 0)
        return 0;
    else if(result < 0)
        return -1;
    else
        return 1;
    
}



void print_usage() {
    printf("sorting_app <filename>\n");
}


void load_data(Array* array, char const* filename ) {
    FILE* file = fopen(filename, "r");

    #define MAX_BUF_LEN 1024
    char buf[MAX_BUF_LEN];

    int id;
    int  field_two;
    double field_three;
    int lineno = 0;
    while(!feof(file)) {
        Record* record = (Record*) malloc(sizeof(Record));

        int n = fscanf(file, "%d,%1024[^,],%d,%lf\n",&id, buf, &field_two, &field_three);
        lineno++;

        if(n != 4) {
            if(feof(file)) {
                continue;
            }

            printf("Error while reading file at line: %d\n", lineno);
            exit(ERROR_EXIT_CODE);
        }
        
        record->id = id;
        record->field_one = strndup(buf, MAX_BUF_LEN);
        record->field_two = field_two;
        record->field_three = field_three;
        Array_insert(array, record);
    }
}

void print_array(Array* array) {
    for(int i=0; i<Array_size(array); ++i) {
        Record* rec = Array_get(array, i);
        printf("id: %10d\t\tfield_one: %20s\t\tfield_two: %10d\t\tfield_three: %15f\n", rec->id, rec->field_one, rec->field_two, rec->field_three);
    }
}

void free_data(Array* array) {
    for(int i=0; i<Array_size(array); ++i) {
        Record* rec = Array_get(array, i);
        free(rec->field_one);
        free(rec);
    }

    Array_free(array);
}

void insertion_sorting(Array* array) {
    signal(SIGALRM,sig_handler);
    alarm(600);
    InsertionSort(array);
    print_array(array);
    
}

void quick_sorting(Array* array) {
    signal(SIGALRM,sig_handler);
    alarm(600);
    QuickSort(array,0,Array_size(array)-1);
    print_array(array);
    
}
// MAIN
// Usage: sorting_app  <filename>

int main(int argc, char const *argv[])
{
    if(argc != 2) {
        printf("Parameters error\n");
        print_usage();
        exit(ERROR_EXIT_CODE);
    }
    
    else{
        Array* array = Array_new((ArrayCmp)compare_first_field);
        load_data(array, argv[1]);
        printf("Insertion sort\nThis is the sorting according to the first field of the record:\n\n");
        insertion_sorting(array);
        ArrayCmp_change(array,(ArrayCmp) compare_second_field);
        printf("Insertion sort\nThis is the sorting according to the second field of the record:\n\n");
        insertion_sorting(array);
        ArrayCmp_change(array,(ArrayCmp) compare_third_field);
        printf("Insertion sort\nThis is the sorting according to the third field of the record:\n\n");
        insertion_sorting(array);
        ArrayCmp_change(array,(ArrayCmp) compare_first_field);
        printf("Quick sort\nThis is the sorting according to the first field of the record:\n\n");
        quick_sorting(array);
        ArrayCmp_change(array,(ArrayCmp) compare_second_field);
        printf("Quick sort\nThis is the sorting according to the second field of the record:\n\n");
        quick_sorting(array);
        ArrayCmp_change(array,(ArrayCmp) compare_third_field);
        printf("Quick sort\nThis is the sorting according to the third field of the record:\n\n");
        quick_sorting(array);
        free_data(array);
    }


    return 0;
}
