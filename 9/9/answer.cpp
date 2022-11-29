#include <iostream>
#include <stdio.h>

using namespace std;
void sortByMerge(int* arr, int n);

int main() {
    FILE* inp = NULL, * outp = NULL;
    int num, n, i = 0;
    int* arr = new int[1000000];
    inp = fopen("input.bin", "rb");
    while (!feof(inp)) {
        fread(&num, sizeof(int), 1, inp);
        if (feof(inp)) break;
        arr[i] = num;
        i++;
    }
    n = arr[0];
    for (int o = 1; o < n + 1; o++) arr[o - 1] = arr[o];
    sortByMerge(arr, n);
    outp = fopen("output.bin", "wb");
    for (int i = 0; i < n; i++)
        fwrite(&arr[i], sizeof(int), 1, outp);
    fclose(inp);
    fclose(outp);
}

void sortByMerge(int* arr, int n) {
    int temp = 1;
    int* arr_temp = (int*)malloc(n * sizeof(int));
    while (temp < n) {
        int i = 0, l = 0, r = l + temp * 2, m = l + temp;
        do {
            if (m >= n) m = n;
            if (r >= n) r = n;
            int i1 = l, i2 = m;
            while (i1 < m && i2 < r) {
                if (arr[i1] < arr[i2]) arr_temp[i++] = arr[i1++];
                else arr_temp[i++] = arr[i2++];
            }
            while (i1 < m) arr_temp[i++] = arr[i1++];
            while (i2 < r) arr_temp[i++] = arr[i2++];
            l = l + temp * 2;
            r = r + temp * 2;
            m = m + temp * 2;
        } while (l < n);
        for (int i = 0; i < n; i++) arr[i] = arr_temp[i];
        temp *= 2;
    }
}
