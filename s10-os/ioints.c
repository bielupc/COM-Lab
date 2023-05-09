#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){
	int i, max;
	
	max = atoi(argv[1]);
	for (i=0; i<max; i++){
		write(3, &i, sizeof(int));
	}
	
}
