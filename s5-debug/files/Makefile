all: fib fib0 fib1 fib2 fib3

fib: fib.c fibonacci.c
	gcc -o fib -g fib.c fibonacci.c

fib0: 
	gcc -o fib0 fib.c fibonacci.c -O0

fib1: 
	gcc -o fib1 fib.c fibonacci.c -O1

fib2:
	gcc -o fib2 fib.c fibonacci.c -O2

fib3:
	gcc -o fib3 fib.c fibonacci.c -O3

clean:
	rm fib
