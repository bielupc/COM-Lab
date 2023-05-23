
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int var, i;
    #pragma omp parallel private(var)
    {
     #pragma omp for 
     for (i=0; i<10; i++) {
        var = i;
        sleep(1); //this function blocks the thread execution for 1 second
        printf("Msg: iterator %d; Var %d; by Thread %d\n", i, var, omp_get_thread_num());
     }
    }
    return 0;

}
