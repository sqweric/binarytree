
CC = g++


main: binarytree.o main.o
	$(CC) binarytree.o main.o -o main


complex.o: binarytree.h complex.cpp
	$(CC) -c binarytree.cpp

main.o: binarytree.h main.cpp
	$(CC) -c main.cpp

clean:
	rm -f binarytree.o main.o main