 CC=gcc

all: main

main: main.o thread_pool.o task.o
	$(CC) -o main main.o thread_pool.o task.o

main.o: src/main.c thread_pool.o src/thread_pool/thread_pool.h
	$(CC) -c src/main.c
 
thread_pool.o: src/thread_pool/thread_pool.c src/thread_pool/thread_pool.h
	$(CC) -c src/thread_pool/thread_pool.c

task.o: src/thread_pool/task.c src/thread_pool/task.h
	$(CC) -c src/thread_pool/task.c

clean: 
	rm -rf *o main