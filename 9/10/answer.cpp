#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define ERROR_FILE_OPEN -3

using namespace std;

void sort(int* a, int n) {
    int i = 0, j = n - 1, mid = a[n / 2];
    do {
        while (a[i] < mid) {
            i++;
        }
        while (a[j] > mid) {
            j--;
        }
        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        sort(a, j + 1);
    }
    if (i < n) {
        sort(&a[i], n - i);
    }
}

int main() {
    FILE* F1 = fopen("input.bin", "rb"), * F2 = fopen("output.bin", "wb");
    int num, a, i = 0, j;
    int* arr = new int[1000000];
    while (!feof(F1)) {
        fread(&num, sizeof(int), 1, F1);
        if (feof(F1))
        {
            break;
        }
        arr[i] = num;
        i++;
    }
    fclose(F1);
    a = arr[0];
    for (j = 1; j < a + 1; j++) {
        arr[j - 1] = arr[j];
    }
    sort(arr, a);
    for (i = 0; i < a; i++) {
        fwrite(&arr[i], sizeof(int), 1, F2);
    }
    fclose(F2);
}
