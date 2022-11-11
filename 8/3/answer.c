#include <stdio.h>
#include <malloc.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int* arr, int minIndex, int maxIndex) {
    if (minIndex >= maxIndex) return;

    int pivot = minIndex - 1;

    for (int i = minIndex; i <= maxIndex; i++) {
        if (arr[i] < arr[maxIndex]) {
            pivot++;
            swap(&arr[pivot], &arr[i]);
        }
    }

    pivot++;
    swap(&arr[pivot], &arr[maxIndex]);

    quickSort(arr, minIndex, pivot - 1);
    quickSort(arr, pivot + 1, maxIndex);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    if (n == 1) {
        printf("%d", arr[0]);
        return 0;
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

//
// Created by letovsk1y on 11/11/2022.
//