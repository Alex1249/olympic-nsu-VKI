#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void mf(int* arr, int n);

int main() {
    FILE* inp = fopen("input.txt", "r");
    int i = 0, n = 0, j = 0, quantity = 0;
    char ch, a = '#';
    int* arr = new int[10000000];
    while (!feof(inp)) {
        fscanf_s(inp, "%c", &ch);
        if ((int(ch) > 12)) {
            arr[i] = int(ch);
            i++;
            quantity++;
        }
    }
    mf(arr, quantity);
    i = 1;
    while (quantity > 0) {
        n = 1;
        while (arr[i] == arr[i - 1]) {
            n++;
            i++;
            --quantity;
        }
        a = '#';
        cout << char(arr[i - 1]) << " ";
        for (j = 0; j < n; j++) cout << a;
        cout << endl;
        i++;
        --quantity;
    }
}

void mf(int* arr, int n) {
    int i = 0, j = n - 1, middle = arr[n / 2];
    do {
        while (arr[i] < middle) i++;
        while (arr[j] > middle) j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) mf(arr, j + 1);
    if (i < n) mf(&arr[i], n - i);
}
