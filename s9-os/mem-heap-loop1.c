#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>

//This function setups a configuration of the heap memory
//  to ease your analysis
//You do not need to understand the details of this function
void setupHeapManagement(){
    int res;

    res = mallopt(M_MMAP_THRESHOLD, 32*1024*1024);
    if (res < 0) perror ("mallopt");
}

//This function returns the current top of the Heap region
//You do not need to understand the details of this function
void *TopHeap(){
    return sbrk(0);
}

int main(int argc, char **argv){
    void *startHeap, *endHeap;
    int len;
    long long numItems;
    char buf[512];
    int *ptr = NULL;

    if (argc != 2){
        len = sprintf(buf, "This program requires a single integer input argument.\n");
        write(1, buf, len);
        return 1;
    }

    numItems = atoll(argv[1]);

    setupHeapManagement();

    //Register the current top limit of the heap
    startHeap = TopHeap();

    endHeap = TopHeap();
    len = sprintf(buf, "Checkpoint 1:\nBefore allocating heap memory to the ptr pointer, the top of the heap is at address %p.\n", endHeap);
    write(1, buf, len);
    read(0, buf, 1);

    for(int i = 0; i < 10; i++){
        ptr = (int *) malloc(numItems * sizeof(int));   
    }

    endHeap = TopHeap();
    len = sprintf(buf, "Checkpoint 2:\nAfter allocating heap memory to the ptr pointer 10 times, the top of the heap is at address %p.\n", endHeap);
    write(1, buf, len);
    read(0, buf, 1);

    free(ptr);     
    endHeap = TopHeap();
    len = sprintf(buf, "Checkpoint 3:\nAfter releasing the memory allocated to the ptr pointer, the top of the heap is at address %p.\n", endHeap);
    write(1, buf, len);
    read(0, buf, 1);

    return 0;
}
