#include <stdio.h>
#include <stdlib.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    int i, j;
    int bucketCount = n;
    float buckets[n][n];
    int bucketSize[n];
    for (i = 0; i < n; i++)
        bucketSize[i] = 0;
    for (i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index][bucketSize[index]++] = arr[i];
    }
    for (i = 0; i < n; i++)
        if (bucketSize[i] > 0)
            insertionSort(buckets[i], bucketSize[i]);
    int k = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < bucketSize[i]; j++)
            arr[k++] = buckets[i][j];
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
}

int main() {
    float arr[] = {1,22,11,6,35,28,91,107};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("\nSorted array:\n");
    printArray(arr, n);
    return 0;
}

