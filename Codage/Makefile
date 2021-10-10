

test_hadamard: test_hadamard.o hadamard.o
	gcc test_hadamard.o hadamard.o -o test_hadamard

test_hadamard.o: test_hadamard.c
	gcc -c test_hadamard.c -o test_hadamard.o

hadamard.o: hadamard.c hadamard.h
	gcc -c hadamard.c -o hadamard.o

