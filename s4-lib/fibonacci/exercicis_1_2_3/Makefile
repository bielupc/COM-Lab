all: fibonacci-orig fibonacci assembly fibonacci.o 

fibonacci-orig: fibonacci-orig.c
	gcc -o fibonacci-orig fibonacci-orig.c

fibonacci: fibonacci.o fib.o
	gcc -o fibonacci fibonacci.o fib.o

fibonacci.o: fibonacci.c fib.h
	gcc -c fibonacci.c

fib.o: fib.c
	gcc -c fib.c

assembly: 
	gcc -S fibonacci.c 
	gcc -S fibonacci-orig.c
	gcc -S fib.c

clean:
	rm fibonacci-orig