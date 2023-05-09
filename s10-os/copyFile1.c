#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main (int argc, char **argv)
{
  int i, f, lenR;

  f = open("./output.dat", O_RDONLY);
  lenR = read(f, &i, sizeof (i));
  while (lenR > 0){
      write (1, &i, sizeof (i));
      lenR = read(f, &i, sizeof (i));
  }
}
