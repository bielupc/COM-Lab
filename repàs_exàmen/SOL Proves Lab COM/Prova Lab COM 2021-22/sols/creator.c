#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXVECTOR 300000
int contador;

int main(int argc, char **argv){
	int fd, i, max, len, option;
	char buf[256];
	int vector[MAXVECTOR];

	if (argc != 4){
		printf("Error en la entrada de parametres\n");
		return 1;
	}
	
	max = atoi(argv[1]);
	
	option = atoi(argv[3]);
	if ((option != 0) && (option != 1)){
		printf("Error en el tercer parametre\n");
		return 1;
	}

	fd = open(argv[2], O_RDONLY, 0644);
	if (fd < 0){
		perror("Error en open");
		return 1;	
	}

	contador = 0;
	
	for (i=0; i<max; i++){
		read(fd, &vector[i], sizeof(int));
		contador++;
	}

	if (option == 1){
		for (i=0; i<max; i++){
			len = sprintf(buf, "%d\n", vector[i]);
			write(1, buf, len);
		}
		len = sprintf(buf, "\nContador=%d\n", contador);
		write(1, buf, len);
	}
		
	close(fd);
	
	return 0;
}
