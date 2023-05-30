#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAXVECTOR 300000
int contador;

int main(int argc, char **argv)
{
  int stride = atoi(argv[4]);
  char buf[256];
  int vector[MAXVECTOR];

  if (argc != 5) {
    printf("Wrong number of arguments\n");
    return 1;
  }

  int num = atoi(argv[1]);
  int option = atoi(argv[3]);

  if ((option != 0) && (option != 1)){
    printf("Wrong third arguments, must be 0 or 1\n");
    return 1;
  }

  int fd = open(argv[2],O_RDONLY);

  if (fd < 0){
    perror("Wrong file name\n");
    return 1;
  }


  contador = 0;
  for (int i = 0; i <num; i++) {
    read(fd, &vector[i], sizeof(int));
    contador++;
  }
  int len;
  if (option == 1){
    for (int i=0; i<num; i=i+stride) {
      len = sprintf(buf, "%d\n",vector[i]);
      write(1, buf, len);
    }
    len = sprintf(buf, "CONTADOR=%d\n", contador);
    write(1, buf, len);
  }
  close(fd);
  return 0;
}
