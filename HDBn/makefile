test_hdbn : test_hdbn.o hdbn.o
	gcc test_hdbn.o hdbn.o -o test_hdbn

test_hdbn.o : test_hdbn.c
	gcc -c test_hdbn.c -o test_hdbn.o

hdbn.o : hdbn.c hdbn.h
	gcc -c hdbn.c -o hdbn.o