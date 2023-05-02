#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int globalVar=0;

//This function returns the current top of the Heap region
//You do not need to understand the details of this function
void *TopHeap(){
	return sbrk(0);
}

//Recursive function till "num" gets "max" value
void Recursivity(int max, int num){
	int len;
	int localVar = num;
	char buf[256];

	localVar++;
	//MISSING CODE: substitute GGG, HHH
	len = sprintf(buf, "The local variable localVar is located at %p when executing recursivity at level %d, holding the value %d\nPress Return to continue...", &localVar, localVar, localVar); 
	write(1, buf, len);
	read(1, buf, 1);
	
	//Check whether to keep recursivity invocation or not
	if (localVar < max){
		Recursivity(max, localVar);
	}	

	//MISSING CODE: substitute III, JJJ
	len = sprintf(buf, "Returning from the function call. Thus, the local variable localVar located at %p in recursivity level %d still holds the value %d\nPress Return to continue...", &localVar, localVar, localVar); 
	write(1, buf, len);
	read(1, buf, 1);
}

int main(int argc, char **argv){
	void *startHeap, *endHeap;
	int len, maxDepth;
	char buf[256];
	int *ptr = NULL;
	
	if (argc != 2){
		len = sprintf(buf, "This program requires a single integer input parameter\n%s Number\n", argv[0]);
		write(1, buf, len);
		return 1;
	}
	
	maxDepth = atoi(argv[1]);

	//Register the current top limit of the heap
	startHeap = TopHeap();
		
	//MISSING CODE: substitute AAA and BBB
	len = sprintf(buf, "Checkpoint 1:\nThe variable pointer ptr is located at %p and now it holds the address %p\nPress Return to continue...", &ptr, ptr);
	write(1, buf, len);
	read(0, buf, 1);

	ptr = &globalVar;
	*ptr = 123;
	//MISSING CODE: substitute CCC, DDD, EEE, FFF
	len = sprintf(buf, "Checkpoint 2:\nThe ptr now points to %p, that is the same address than globalVar1 %p\nThus, both have the same integer value %d vs %d\nPress Return to continue...", ptr, &globalVar, globalVar, *ptr);
	write(1, buf, len);
	read(0, buf, 1);
	
	endHeap = TopHeap();
	len = sprintf(buf, "Checkpoint 3:\nIn this code, heap memory region has a size of %d Bytes\nPress Return to continue...", (int)(endHeap - startHeap));
	write(1, buf, len);
	read(0, buf, 1);
	
	len = sprintf(buf, "Checkpoint 4:\nNow, we are going to execute a recursive function call using the input parameter to indicate the recursivity depth (a total of %d)\nPress Return to continue...", maxDepth);
	write(1, buf, len);
	read(0, buf, 1);
	
	Recursivity(maxDepth, 0);
	
	return 0;
}
