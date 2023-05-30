all: matrix-row matrix-column matrix-row-dyn matrix-row-sta

matrix-row-dyn: matrix-row.o
	gcc -o matrix-row-dyn matrix-row.o

matrix-row-sta: matrix-row.o
	gcc -o matrix-row-sta matrix-row.o -static

matrix-column: matrix-column.c
	gcc -o matrix-column matrix-column.c

matrix-row: matrix-row.o
	gcc -o matrix-row matrix-row.o

matrix-row.o: matrix-row.c
	gcc -c matrix-row.c

clean:
	rm -f *.o
	rm -f matrix-row matrix-column matrix-row-dyn matrix-row-sta

