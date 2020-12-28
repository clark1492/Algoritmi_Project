CFLAGS = -g -O0 -I include/ -I Resources/C/Unity/

all: bin/test_string bin/test_int bin/test_double  bin/sorting_app

clean:
	$(RM) -rf bin/*
	$(RM) -rf build/*

build/array.o: src/array.c include/array.h
	$(CC) $(CFLAGS) -c src/array.c -o build/array.o
	
bin/sorting_app: include/array.h build/array.o sorting_app/sorting_app.c
	$(CC) $(CFLAGS) -o bin/sorting_app build/array.o sorting_app/sorting_app.c

bin/test_string: test/test_string.c build/array.o include/array.h
	$(CC) $(CFLAGS)	test/test_string.c build/array.o Resources/C/Unity/unity.c -o bin/test_string

bin/test_int: test/test_int.c build/array.o include/array.h
	$(CC) $(CFLAGS)	test/test_int.c build/array.o Resources/C/Unity/unity.c -o bin/test_int

bin/test_double: test/test_double.c build/array.o include/array.h
	$(CC) $(CFLAGS)	test/test_double.c build/array.o Resources/C/Unity/unity.c -o bin/test_double