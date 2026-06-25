#include <stdio.h>
#include <stdlib.h>

// function to compare two integers (used in qsort)
int compare(void* a, void* b) {
    return (*(int*)a - *(int*)b);
}

// function to merge two sorted arrays in-place
void mergeArrays(int arr1[], int arr2[], int n, int m) {
    // temporary array to store all elements 
    // from arr1 and arr2
    int* merged = (int*)malloc((n + m) * sizeof(int));

    // copy elements from arr1 and arr2 into merged array
    for (int i = 0; i < n; ++i) {
        merged[i] = arr1[i];
    }
    for (int j = 0; j < m; ++j) {
        merged[n + j] = arr2[j];
    }

    // sort the merged array
    qsort(merged, n + m, sizeof(int), compare);

    // distribute first n elements to arr1
    for (int i = 0; i < n; ++i) {
        arr1[i] = merged[i];
    }

    // distribute remaining m elements to arr2
    for (int j = 0; j < m; ++j) {
        arr2[j] = merged[n + j];
    }

    // free dynamically allocated memory
    free(merged);
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    mergeArrays(arr1, arr2, n, m);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    for (int i = 0; i < m; ++i) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}