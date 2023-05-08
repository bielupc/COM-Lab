all: mem-stack mem-stack-2 mem-heap-orig mem-heap-loop1

mem-stack: mem-stack.c
	gcc -o mem-stack mem-stack.c

mem-stack-2: mem-stack-2.c
	gcc -o mem-stack-2 mem-stack-2.c

mem-heap-orig: mem-heap-orig.c
	gcc -o mem-heap-orig mem-heap-orig.c

mem-heap-loop1: mem-heap-loop1.c
	gcc -o mem-heap-loop1 mem-heap-loop1.c

clean:
	rm -f mem-stack mem-stack-2 mem-heap-orig
