#include <stdio.h>
#include <stdlib.h>
#define MEGA 1048576

int main(int argc, char **argv)
{
	int i, j, size;
	int res = 0, op1, op2;
	size = 100*MEGA;
	
	for (j=0;j<25; j++) {
		for (i=0; i<size; i++){
			op1 = rand();
			op2 = rand();
			res += op1 + op2;
		}
	}

	printf ("integers: res: %d\n", res);
	return 0;
}
