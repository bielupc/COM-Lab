#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fibonacci.h"

// https://ca.wikipedia.org/wiki/Leonardo_de_Pisa

int main(int argc, char * argv[])
{
   char c;
   if (argc != 2) {
      fprintf(stderr, "Us: %s <number>\n"
  "   where <number> is the number from which to compute fibonacci(number).\n",
       argv[0]);
      exit(1);
   }

   unsigned long num = strtol(argv[1], NULL, 0);
   unsigned long result = fibonacci(num);
   printf ("fibonacci(%lu) = %lu\n", num, result);
   //read(0, &c, 1);

   return 0;
}
