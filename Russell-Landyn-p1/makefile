CC    = g++
FLAGS = -Wall -pedantic-errors

compile:
	$(CC) $(FLAGS) -c -o Matrix.o Matrix.cpp
	$(CC) $(FLAGS) -c -o p1.o p1.cpp
	$(CC) -o p1 p1.o Matrix.o

run: compile
	./p1

clean:
	rm -f p1
	rm -f Matrix.o
	rm -f p1.o
