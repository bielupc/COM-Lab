#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main (int argc, char **argv)
{
  char c;
  int ret;

  ret = read (0, &c, sizeof (c));
  while (ret > 0){
      write (1, &c, sizeof (c));
      ret = read (0, &c, sizeof (c));
  }
}
