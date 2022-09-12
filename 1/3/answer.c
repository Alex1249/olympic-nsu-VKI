#include <stdio.h>
#include <malloc.h>

int* allocateArray(int length) {
    return (int *)malloc(length * sizeof(int));
}

int main() {
    int n;

    scanf_s("%d", &n);

    int* arr = allocateArray(n);

    for (int i = 0; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 2; i * i <= n + 1; i++) {
        if (arr[i]) {
            for (int j = i * i; j <= n; j += i) {
                arr[j] = 0;
            }
        }
    }
    for (int i = 2; i < n + 1; i++) {
        if (arr[i]) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
//
// Created by letovsk1y on 9/12/2022.
//
