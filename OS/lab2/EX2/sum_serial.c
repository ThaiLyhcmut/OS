#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of numbers from 1 to n
long long sum_serial(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    long long result = sum_serial(n);
    printf("Sum of numbers from 1 to %d is %lld\n", n, result);

    return 0;
}
