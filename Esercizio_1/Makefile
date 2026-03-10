CC = gcc

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = -Isrc

COMMON_DEPS = Makefile

all: bin/merge_binary_insertion_sort bin/merge_binary_insertion_sort_tests

run_app:
	./bin/merge_binary_insertion_sort ../data/records.csv 1 35

run_test:
	./bin/merge_binary_insertion_sort_tests

build/%.o: src/%.c $(COMMON_DEPS)
	mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bin/merge_binary_insertion_sort: build/array.o build/merge_binary_insertion_sort.o build/merge_binary_insertion_sort_main.o
	mkdir -p bin
	mkdir -p output
	$(CC) -o $@ $^

bin/merge_binary_insertion_sort_tests: build/merge_binary_insertion_sort_tests.o build/merge_binary_insertion_sort.o build/unity.o
	mkdir -p bin
	$(CC) -o $@ $^

clean:
	rm -rf build bin output