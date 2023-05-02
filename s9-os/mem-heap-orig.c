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
		len = sprintf(buf, "This program requires a single integer input parameter\n%s Number\n", argv[0]);
		write(1, buf, len);
		return 1;
	}
	
	numItems = atoll(argv[1]);

	setupHeapManagement();
	
	//Register the current top limit of the heap
	startHeap = TopHeap();
	
	endHeap = TopHeap();
	len = sprintf(buf, "Checkpoint 1:\nBefore allocating heap memory to the ptr, the heap memory region has a size of %d Bytes\nPress Return to continue...", (int)(endHeap - startHeap));
	write(1, buf, len);
	read(0, buf, 1);
	
	ptr = (int *) malloc(numItems * sizeof(int));	
	endHeap = TopHeap();

	len = sprintf(buf, "Checkpoint 2:\nAfter allocating heap memory, ptr now points to %p and Heap size is %d Bytes\nPtr holds an array of %lld integers (%lld Bytes)\nFirst item has address %p\nLast item has address %p\nPress Return to continue...", ptr, (int) (endHeap - startHeap), numItems, (numItems * sizeof(int)), &ptr[0], &ptr[numItems-1]);
	write(1, buf, len);
	read(0, buf, 1);
	
	free(ptr);	
	endHeap = TopHeap();
	len = sprintf(buf, "Checkpoint 3:\nAfter releasing the memory allocated to ptr, the heap region has a size of %d Bytes\nPress Return to continue...", (int) (endHeap - startHeap));
	write(1, buf, len);
	read(0, buf, 1);
	
	return 0;
}
