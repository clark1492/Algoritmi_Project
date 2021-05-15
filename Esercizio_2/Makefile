
all: bin/tests bin/editdistance

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/editdistance: build/termlist.o build/main.o build/array.o build/editdistance.o $(COMMON_DEPS)
	$(CC) -o bin/editdistance build/main.o build/termlist.o build/array.o build/editdistance.o 

bin/tests: build/tests.o build/editdistance.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/tests  build/tests.o build/editdistance.o build/unity.o

clean:
	rm -f build/* bin/*
