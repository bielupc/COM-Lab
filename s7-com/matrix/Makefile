all: matinit-row matinit-column

matinit-row: matinit.c
	gcc -O0 -DROW -o matinit-row matinit.c

matinit-column: matinit.c
	gcc -O0 -DCOLUMN -o matinit-column matinit.c

clean:
	rm matinit-row matinit-column cachegrind*
