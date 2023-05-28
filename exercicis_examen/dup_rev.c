#include <stdio.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
  int fdin, fdout, max, pos, i;
  char c;

  fdout = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0664);
  if (fdout < 0){
    perror("Error en open input");
    return 0;
  }

  max = lseek(fdin, 0, SEEK_END);
  for (i = 0; i <= max; i++)
  {
    pos = lseek(fdin, (-1)*i, SEEK_END);
    read(fdin, &c, sizeof(int));
    write(fdout, &c, sizeof(int));
  }
   return 0;
}



