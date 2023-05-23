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

int main(int argc, char **argv)
{
    int totalCount = 0; // Number of total chars
    int localCount = 0; // Number of chars read per thread

    int histo[128];     // Histogram of chars
    char c;             // Char read

    double t0; // Start time
    double t1; // End time

    // Initialize histogram
    for (int i = 0; i < 128; i++)
        histo[i] = 0;

    // Take start time
    t0 = now();

    // START OF THE CODE TO BE PARALLELIZED
    #pragma omp parallel shared(histo, totalCount) private(c, localCount)
    {
        int threadCount = omp_get_num_threads();
        int threadID = omp_get_thread_num();

        // Calculate workload distribution among threads
        #pragma omp single
        printf("Number of threads: %d\n", threadCount);

        // Initialize local histogram
        int localHisto[128];
        for (int i = 0; i < 128; i++)
            localHisto[i] = 0;

        // Read characters and update local histogram
        while (read(0, &c, 1) > 0)
        {
            localHisto[c]++;
            localCount++;
        }

        // Accumulate local histograms into the global histogram
        #pragma omp critical
        {
            for (int i = 0; i < 128; i++)
                histo[i] += localHisto[i];
            totalCount += localCount;
        }

        // Print the number of characters processed by each thread
        #pragma omp barrier
        #pragma omp single
        {
            for (int i = 0; i < threadCount; i++)
                printf("Thread %d processed %d characters.\n", i, localCount);
        }
    }
    // END OF THE CODE TO BE PARALLELIZED

    // Take "end" time
    t1 = now();

    // Print histogram results to stderr
    for (int i = 0; i < 128; i++)
        fprintf(stderr, "Char %d: there are %d\n", i, histo[i]);

    // Print stats to stdout
    printf("Total characters: %d\n", totalCount);
    printf("Time: %lf s\n", t1 - t0);

    return 0;
}

