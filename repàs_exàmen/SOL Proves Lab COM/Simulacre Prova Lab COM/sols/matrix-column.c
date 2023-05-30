#include <stdio.h>
#include <stdlib.h>

int mat[1024][1024];

int main(int argc, char **argv)
{
	int x,y;

	x = atoi(argv[1]);
	y = atoi(argv[2]);

	if ((x>1024)||(y>1024))
	{
		printf("Los valores son mayores que 1024\n");
		exit(0);
	}

	printf("Recorrere %d filas y %d columnas\n", x, y);

	for (int posy = 0; posy < y; posy ++)
	{
		for (int posx = 0; posx < x; posx ++)
		{
			mat[posx][posy] = posx * posy;
		}
	}

	return 0;
}

