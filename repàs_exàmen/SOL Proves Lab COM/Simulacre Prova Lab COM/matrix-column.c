#include <stdio.h>
#include <string.h>

int mat[1024][1024];

int main(int argc, char *argv[])
{
  int x = atoi(argv[1]);
  int y = atoi(argv[2]);



  if ((sizeof(x)>1024) || (sizeof(y)>1024)) {
    printf("Error\n");
    return 1;
  }

  printf("We'll go through %d rows and %d columns \n", x, y);

  for (int i=0; i<x; i++) {
    for (int j=0; j<y; j++) {
      mat[j][i] = i*j;
    }
  }

  return 0;
}
