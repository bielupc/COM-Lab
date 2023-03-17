all: matmul

matmul: matmul.c
	gcc -O0 -DROW -o matmul-0 matmul.c
	gcc -O1 -DROW -o matmul-1 matmul.c
	gcc -O2 -DROW -o matmul-2 matmul.c
	gcc -O3 -DROW -o matmul-3 matmul.c

clean:
	rm matmul-*
