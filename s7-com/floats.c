#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MEGA 1048576

int main(int argc, char **argv)
{
	int i, j, size;
	float res = 0, op1, op2;
	size = 100*MEGA;
	
	for (j=0;j<25; j++) {
		for (i=0; i<size; i++){
			op1 = rand();
			op2 = rand();
			res += (float)op1/(float)op2;
		}
	}

        printf ("floats: res: %f\n", res);
	return 0;
}
