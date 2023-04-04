#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void Usage(char * param){
	printf("This program needs integer number/s as input parameter/s. It will write binary format.\n");
}
	
int main(int argc, char **argv){

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	float num;

	num = (float) a / b;
	write(1, &num, sizeof(float));

	return 0;	
}
