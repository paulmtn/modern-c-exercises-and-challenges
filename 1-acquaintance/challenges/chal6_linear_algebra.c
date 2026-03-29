#include <stdio.h>

void print_vector(double vector[], size_t size) {
    printf("[");
    for (size_t i = 0; i < size; ++i) {
        printf("%g", vector[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void print_matrix(size_t m, size_t n, double matrix[m][n]) {
    for (size_t i = 0; i < m; ++i) {
        print_vector(matrix[i], n);
    }
}
double vector_vector_multiplication(double v1[], double v2[], size_t size) {
    double result = 0;
    for (size_t i = 0; i < size; ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

void matrix_vector_multiplication(double result[], size_t m, size_t n, double matrix[m][n], double v1[], size_t v1_size) {
    if (n != v1_size) {
        printf("Wrong size for multiplication\n");
        return;
    }

    for (size_t i = 0; i < m; ++i) {
        result[i] = vector_vector_multiplication(matrix[i], v1, v1_size);
    }
}

void gaussian_elimination(size_t m, size_t n, double matrix[m][n]) {
    // for each pivot except the last one
    for (size_t i = 0; i < m - 1; ++i) {
        // for each row below the pivot
        for (size_t j = i + 1; j < m; ++j) {
            // divide the ith element of the row below the pivot row by the pivot and subtract from each column
            double factor = matrix[j][i] / matrix[i][i];
            for (size_t k = 0; k < n; ++k) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

int main(void) {
    double vector1[] = {1, 5, 2, 8};
    double vector2[] = {9, 2, 1, 6};
    size_t size = sizeof(vector1)/sizeof(vector1[0]);

    printf("vector 1: "); 
    print_vector(vector1, size);

    printf("vector 2: "); 
    print_vector(vector2, size);

    printf("Dot product of vector 1 and vector 2: %g\n", vector_vector_multiplication(vector1, vector2, size));

    printf("\n");
    #define M 3
    #define N 4
    double matrix1[M][N] = { 
        {2, 5, 1, 5},
        {6, 2, 3, 3},
        {9, 6, 5, 5},
    };
    printf("matrix 1: \n");
    print_matrix(M, N, matrix1);
    printf("vector 1: \n"); 
    print_vector(vector1, size);

    double result[M];
    matrix_vector_multiplication(result, M, N, matrix1, vector1, size);
    printf("Matrix multiplication of matrix1 and vector1: \n");
    print_vector(result, M);

    printf("\n");
    printf("Gaussian elimination of  matrix 1: \n");
    gaussian_elimination(M, N, matrix1);
    print_matrix(M, N, matrix1);
}

