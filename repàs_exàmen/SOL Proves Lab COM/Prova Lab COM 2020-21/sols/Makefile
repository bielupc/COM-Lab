
all: do-gen-plot executa

executa: executa.c
	gcc -o executa -O executa.c


do-gen-plot: do-gen-plot.cpp
	g++ -o do-gen-plot -O do-gen-plot.cpp


clean:
	rm -f do-gen-plot executa
