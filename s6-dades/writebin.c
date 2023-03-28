#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void Usage(char * param){
	printf("This program needs integer number/s as input parameter/s. It will write binary format.\n");
}
	
int main(int argc, char **argv){
	int i;
    char character;
    int num;
    short short_num;
    long long_num;
    long long long_long_num;

    if (argc == 1){
        Usage(argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "char") == 0){
        for (i=2; i<argc; i++){
            character = atoi(argv[i]);
            write(1, &character, sizeof(char));
        }
    }
    else if (strcmp(argv[1], "short") == 0){
        for (i=2; i<argc; i++){
            short_num = atoi(argv[i]);
            write(1, &short_num, sizeof(short));
        }
    }
    else if (strcmp(argv[1], "int") == 0){
        for (i=2; i<argc; i++){
            num = atoi(argv[i]);
            write(1, &num, sizeof(int));
        }
    }
    else if (strcmp(argv[1], "long") == 0){
        for (i=2; i<argc; i++){
            long_num = atol(argv[i]);
            write(1, &long_num, sizeof(long));
        }
    }
    else if (strcmp(argv[1], "longlong") == 0){
        for (i=2; i<argc; i++){
            long_long_num = atoll(argv[i]);
            write(1, &long_long_num, sizeof(long long));
        }
    }
    else{
        Usage(argv[0]);
        return 1;
    }
    
    return 0;
}

