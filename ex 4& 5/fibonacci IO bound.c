#include <stdio.h>
#include <time.h>

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    clock_t start, end;
    double runTime;

    start = clock();

    int n;
    printf("Enter the number of Fibonacci terms to calculate: ");
    scanf("%d", &n);

    printf("Calculating Fibonacci series...\n");

    for (int i = 0; i < n; ++i) {
        long long result = fibonacci(i);
        printf("Fibonacci(%d) = %lld\n", i, result);
        fflush(stdout); // Flush the output buffer to show progress

        // Introduce a delay to simulate I/O bound behavior
        for (int delay = 0; delay < 1000000; ++delay);
    }

    end = clock();
    runTime = (end - start) / (double)CLOCKS_PER_SEC;

    printf("Calculation completed in %g seconds\n", runTime);

    return 0;
}
