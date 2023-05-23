#include <stdio.h>
#include <string.h>
#include <omp.h>
#include <unistd.h>
#include <sys/time.h>

double now()
{
   struct timeval tv;
   int res = gettimeofday(&tv, NULL);
   if (res < 0) perror("gettimeofday");
   double t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
   return t;
}

int main(int argc, char **argv){
	//IMPORTANT VARIABLES TO BE MANAGED FOR THE DEVELOPMENT
	//Feel free to modify any variable declaration placement if you consider it is necessary
	int totalCount = 0;//Number of total chars
	int localCount = 0;//Number of chars read per thread

	int histo[128];    //Histogram of chars
	char c; //Char read
	
	int i = 0; //iterator
	int len = 0;
	char buf[256];

	double t0; //start time
	double t1; //end time
	
	//Initialize histogram
	for (i=0; i<128; i++)
		histo[i]=0;
		
	//Take start time
	t0 = now();

	//START OF THE CODE TO BE PARALLELIZED
	//...
	#pragma omp parallel
		{
		while (read(0, &c, 1) > 0) {
			//...	
		}
	}
	//...	
	//END OF THE CODE TO BE PARALLELIZED

	//take "end" time
	t1 = now();

	//print histogram results
	localCount = 0;
	for (i=0; i<128; i++){
		len = sprintf(buf,"Char %d: there are %d\n", i, histo[i]);
		write(2, buf, len);
		localCount += histo[i];
	}
	
	//show processing time
	printf("Total %d vs %d\nTime: %lf s\n", totalCount, localCount,  t1 - t0);

	return 0;
}



