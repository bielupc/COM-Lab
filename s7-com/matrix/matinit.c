#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <errno.h>

#define SIZE 4496
//#define SIZE 2248
//#define SIZE 1224
//#define SIZE 656
#define TYPE float

int size_input=0;

#ifdef COLUMN
// activate for column-wise accesses
#define ACCESS(i,j) (((j)*size_input)+(i))
#else
// activate for row-wise accesses 
#define ACCESS(i,j) (((i)*size_input)+(j))
#endif

// forward function declarations
double now();
void show_time(char * msg, double t0, double t1);
TYPE * matrix_allocate(char * name, int rows, int cols);


//////////////////////////////////////////////////////////////////////////
/////////////// function for matrix initialization ///////////////////////

void matrix_init(char * msg, TYPE * mat, int rows, int cols, TYPE random)
{
 int loop;
 int i, j;

 double t0, t1;

 for (loop = 0; loop < 4; loop++) {
   t0 = now();

   for (i=0; i < rows; i++) {
      for (j=0; j < cols; j++) {
         TYPE value = random * ((TYPE) (1.0/((TYPE) i+0.25)) - 0.005*j);
         mat[ACCESS(i,j)] = value;
      }
   }

   t1 = now();

   show_time(msg, t0, t1);
 }
 printf("\n");
}


//////////////////////////////////////////////////////////////////////////
////////////////////////////    main     /////////////////////////////////

int main(int argc, char * argv [])
{
   int i;

	if (argc == 2)
		size_input = atoi(argv[1]);
	else
		size_input = SIZE;

   TYPE * A = matrix_allocate("A", size_input, size_input);
   TYPE * B = matrix_allocate("B", size_input, size_input);
   TYPE * C = matrix_allocate("C", size_input, size_input);

   matrix_init("init(A)", A, size_input, size_input, 0.04);
   matrix_init("init(B)", B, size_input, size_input, 0.07);
   matrix_init("init(C)", C, size_input, size_input, 0.0);   // 0.0 to initialize = 0.0
   
#ifdef COLUMN
   printf("Initialized matrixes of %d X %d (%d Bytes each element) accessing column-wise\n", size_input, size_input, (int)sizeof(TYPE));
#else
   printf("Initialized matrixes of %d X %d (%d Bytes each element) accessing row-wise\n", size_input, size_input, (int)sizeof(TYPE));
#endif

 return 0;
}




//////////////////////////////////////////////////////////////////////
/////////////////// Auxiliary functions //////////////////////////////


TYPE * matrix_allocate(char * name, int rows, int cols)
{
   TYPE * m = (TYPE *) malloc(rows*cols*sizeof(TYPE));
   if (m == NULL) {
      fprintf(stderr, "malloc(%s): %s\n", name, strerror(errno));
      exit(1);
   }
   return m;
}


double now()
{
   struct timeval tv;
   int res = gettimeofday(&tv, NULL);
   if (res < 0) perror("gettimeofday");
   double t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
   return t;
}

void show_time(char * msg, double t0, double t1)
{
   fprintf (stderr, "%s: %lf s\n", msg, t1 - t0);
}
