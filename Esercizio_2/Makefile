all: bin/edit_distance bin/edit_distance_tests

run_app: 
	./bin/edit_distance ../Data/correctme.txt ../data/dictionary.txt

run_test: 
	./bin/edit_distance_tests

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

bin/edit_distance: build/edit_distance_main.o build/string_array.o build/termlist.o build/edit_distance.o $(COMMON_DEPS)
	mkdir -p bin
	$(CC) -o bin/edit_distance build/edit_distance_main.o build/string_array.o build/termlist.o build/edit_distance.o 

bin/edit_distance_tests: build/edit_distance_tests.o build/edit_distance.o build/unity.o $(COMMON_DEPS)
	mkdir -p bin
	$(CC) -o bin/edit_distance_tests build/edit_distance_tests.o build/edit_distance.o build/unity.o

clean:
	rm -rf build bin