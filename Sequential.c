#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024

void matrixMultiply(int* A, int* B, int* C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i * n + k] * B[k * n + j];
            }
            C[i * n + j] = sum;
        }
    }
}

int main() {
    int* A, * B, * C; // Matrices
    int size = N * N * sizeof(int);

    // Allocate memory for matrices
    A = (int*)malloc(size);
    B = (int*)malloc(size);
    C = (int*)malloc(size);

    // Initialize matrices
    for (int i = 0; i < N * N; i++) {
        A[i] = i;
        B[i] = i;
    }

    // Measure time
    clock_t start = clock();

    // Perform matrix multiplication
    matrixMultiply(A, B, C, N);

    // Calculate elapsed time
    clock_t end = clock();
    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;

    printf("Matrix multiplication took %.3f milliseconds\n", elapsed_time);

    // Free memory
    free(A);
    free(B);
    free(C);

    return 0;
}
