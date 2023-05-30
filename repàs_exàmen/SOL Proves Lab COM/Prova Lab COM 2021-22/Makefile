all: creator creator2

creator: creator.c
	gcc -o creator creator.c

creator2: creator2.c
	gcc -o creator2 creator2.c

entregar: answers.txt Makefile creator.c creator2.c
	tar czvf ProvaLab.tar.gz answers.txt Makefile creator.c creator2.c

clean:
	rm -r creator2 creator 
