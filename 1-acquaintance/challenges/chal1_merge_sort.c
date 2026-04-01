#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool testSorted(double arr[], size_t length) {
    for (size_t i = 1; i < length; ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

// 0 1 2 3 4
// left = 0, mid = 2, right = 4
void merge(double arr[], size_t left, size_t middle, size_t right) {
    double temp[right - left + 1];
    
    size_t i = left;
    size_t j = middle + 1;
    size_t k = 0;

    while (i <= middle && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // dump remaining values
    while (i <= middle) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (size_t n = 0; n < right - left + 1; n++) {
        arr[left + n] = temp[n];
    }
}
void merge_sort(double arr[], size_t left ,size_t right) {
    if (left >= right) {
        return;
    }

    size_t middle = (left + right) / 2;

    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

int main(void) {
    double arr[] = {2.1, 5.3, 1.8, 10, 8.8, 4, 5.5, 1.2, 1.2, 1.6};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, length - 1);

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