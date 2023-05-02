all: mem-stack mem-heap-orig

mem-stack: mem-stack.c
	gcc -o mem-stack mem-stack.c

mem-stack: mem-stack-2.c
	gcc -o mem-stack-2 mem-stack-2.c

mem-heap-orig: mem-heap-orig.c
	gcc -o mem-heap-orig mem-heap-orig.c

clean:
	rm -f mem-stack
