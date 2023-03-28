#include <stdio.h>
#include <unistd.h>
	
int main(int argc, char **argv){
	int i=0;
    char character;
    int num;
    short short_num;
    long long_num;
    long long long_long_num;

    if (strcmp(argv[1], "char") == 0){
		while(read(0, &character, sizeof(char))){
			printf("value: %c (%d decimal value)\n", character, character); 
		}
	}
    else if (strcmp(argv[1], "int") == 0){
		while(read(0, &num, sizeof(int))){
			printf("value: %c (%d decimal value)\n", num, num); 
		}
	}
    else if (strcmp(argv[1], "short") == 0){
		while(read(0, &short_num, sizeof(short))){
			printf("value: %c (%d decimal value)\n", short_num, short_num); 
		}
	}
    else if (strcmp(argv[1], "long") == 0){
		while(read(0, &long_num, sizeof(long))){
			printf("value: %c (%d decimal value)\n", long_num, long_num); 
		}
	}
   	else if (strcmp(argv[1], "longlong") == 0){
		while(read(0, &long_long_num, sizeof(long long))){
			printf("value: %c (%d decimal value)\n", long_long_num, long_long_num); 
		}
	}

	return 0;	
}
