CC    = gcc
FLAGS = -Wall -pedantic-errors

compile:
	$(CC) $(FLAGS) -o head head.c
	$(CC) $(FLAGS) -o tail tail.c
	$(CC) $(FLAGS) -o wc wc.c
	$(CC) $(FLAGS) -o true true.c
	$(CC) $(FLAGS) -o false false.c
	$(CC) $(FLAGS) -o env env.c

clean:
	rm -f head
	rm -f tail
	rm -f wc
	rm -f true
	rm -f false
	rm -f env
