
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int n = 10; 
    if (argc > 1) {
        n = atoi(argv[1]);
    }
    
    
    char buf[256]; 
    #pragma omp parallel num_threads(n)
    {
        int thid = omp_get_thread_num(); 
        sprintf(buf, "I am thread %d\n", thid);
        write(1, buf, strlen(buf));
        
    }
    
    return 0;
}
