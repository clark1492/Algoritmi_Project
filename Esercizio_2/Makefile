
all: bin/edit_distance_tests bin/edit_distance

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/edit_distance: build/edit_distance_main.o build/char_array.o build/termlist.o build/edit_distance.o $(COMMON_DEPS)
	$(CC) -o bin/edit_distance build/edit_distance_main.o build/char_array.o build/termlist.o build/edit_distance.o 

bin/edit_distance_tests: build/edit_distance_tests.o build/edit_distance.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/edit_distance_tests build/edit_distance_tests.o build/edit_distance.o build/unity.o

clean:
	rm -f build/* bin/*
