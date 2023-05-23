
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int var, i;
    #pragma omp parallel shared(var)
    {
     #pragma omp for 
     for (i=0; i<10; i++) {
        #pragma omp critical
        {
        var = i;
        sleep(1); 
        printf("Msg: iterator %d; Var %d; by Thread %d\n", i, var, omp_get_thread_num());
        }
     }
    }
    return 0;

}