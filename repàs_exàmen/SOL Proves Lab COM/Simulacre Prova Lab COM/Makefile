all: matrix-row matrix-column matrix-row-object matrix-row-dyn matrix-row-sta

matrix-row: matrix-row.c
	gcc -o matrix-row matrix-row.c

matrix-column: matrix-column.c
	gcc -o matrix-column matrix-column.c

matrix-row-dyn: matrix-row.o
	gcc -o matrix-row-dyn matrix-row.o

matrix-row-sta: matrix-row.o
	gcc -o matrix-row-sta matrix-row.o -static

matrix-row-object: matrix-row.c
	gcc -c -o matrix-row.o matrix-row.c


clean:
	rm -r matrix-row matrix-column
