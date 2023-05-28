#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv){
  int fd;
  fd = open(argv[0], O_RDRW);

  if (fd < 0){
    perror("Error en open");
  }
}
