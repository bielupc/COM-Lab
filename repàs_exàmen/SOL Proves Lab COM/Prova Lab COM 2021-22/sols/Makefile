all: creator creator-static creator2 

creator: creator.c
	gcc -o creator creator.c

creator-static: creator.c
	gcc -o creator-static -static creator.c
	
creator2: creator2.c
	gcc -o creator2 creator2.c
	
clean:
	rm creator creator-static creator2

entrega:
	tar czvf ProvaLab.tar.gz answers.txt Makefile creator.c creator2.c
	