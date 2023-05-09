
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main (int argc, char **argv)
{
  int ret;
  char buf[100];

  ret = read (0, buf, 100);
  while (ret > 0){
      write (1, buf, ret);
      ret = read (0, buf, 100);
  }
}
