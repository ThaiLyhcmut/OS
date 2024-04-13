#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to pass arguments to thread function
typedef struct {
    int start;
    int end;
    long long *sum;
} ThreadArgs;

// Thread function to calculate the sum of numbers from start to end
void *calculate_sum(void *args) {
    ThreadArgs *t_args = (ThreadArgs *)args;
    long long sum = 0;
    for (int i = t_args->start; i <= t_args->end; i++) {
        sum += i;
    }
    *(t_args->sum) = sum;
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <numThreads> <n>\n", argv[0]);
        return 1;
    }

    int numThreads = atoi(argv[1]);
    int n = atoi(argv[2]);
    long long result = 0;
    pthread_t threads[numThreads];
    ThreadArgs t_args[numThreads];

    // Create threads and assign work to each thread
    for (int i = 0; i < numThreads; i++) {
        t_args[i].start = (i * n) / numThreads + 1;
        t_args[i].end = ((i + 1) * n) / numThreads;
        t_args[i].sum = &result;
        pthread_create(&threads[i], NULL, calculate_sum, (void *)&t_args[i]);
    }

    // Join threads and accumulate results
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sum of numbers from 1 to %d is %lld\n", n, result);

    return 0;
}
