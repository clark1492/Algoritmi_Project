
all: bin/merge_binary_insertion_sort bin/merge_binary_insertion_sort_tests

run_app: 
				./bin/merge_binary_insertion_sort ../Data/records.csv 1 35

run_test: 
				./bin/merge_binary_insertion_sort_tests

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/merge_binary_insertion_sort: build/array.o build/merge_binary_insertion_sort.o build/merge_binary_insertion_sort_main.o $(COMMON_DEPS)
	$(CC) -o bin/merge_binary_insertion_sort build/array.o build/merge_binary_insertion_sort.o build/merge_binary_insertion_sort_main.o

bin/merge_binary_insertion_sort_tests: build/merge_binary_insertion_sort_tests.o build/merge_binary_insertion_sort.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/merge_binary_insertion_sort_tests  build/merge_binary_insertion_sort_tests.o build/merge_binary_insertion_sort.o build/unity.o

clean:
	rm -f build/* bin/* output/*
