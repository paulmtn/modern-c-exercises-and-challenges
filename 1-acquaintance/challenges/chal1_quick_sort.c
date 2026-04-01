#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void quick_sort(double arr[], size_t left, size_t right);
size_t partition(double arr[], size_t left, size_t right);
void swap(double arr[], size_t i, size_t j);
bool testSorted(double arr[], size_t length);

int main(void) {
    double arr[] = {2.1, 5.3, 1.8, 10, 8.8, 4, 5.5, 1.2, 1.2, 1.6};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, length - 1);

    if (testSorted(arr, length)) {
        printf("sorted!\n");
    } else {
        printf("not sorted\n");
    }

    for (size_t i = 0; i < length; ++i) {
        printf("%.1f ", arr[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}

bool testSorted(double arr[], size_t length) {
    for (size_t i = 1; i < length; ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

// 0 1 2 3 4
// 4 1 2 3 0
// low = 0, high = 4
void quick_sort(double arr[], size_t left, size_t right) {
    if (left < right) {
        size_t pivot_index = partition(arr, left, right);
        if (pivot_index > 0) {
            quick_sort(arr, left, pivot_index - 1);
        }
        quick_sort(arr, pivot_index + 1, right);
    } 
}

size_t partition(double arr[], size_t left, size_t right) {
    double pivot = arr[right];

    size_t i = left;
    for (size_t j = left; j < right; ++j) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            ++i;
        }
    }
    swap(arr, i, right);
    return i;
}

void swap(double arr[], size_t i, size_t j) {
    double temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

