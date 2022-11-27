using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ERROR_FILE_OPEN -3

int main() {
    FILE* in = NULL, * out = NULL;
    long int num, a;
    long float amount = 0;
    in = fopen("input.bin", "rb");
    while (!feof(in)) {
        fread(&num, sizeof(int), 1, in);
        if (feof(in))
            break;
        cout << num << " ";
        amount += num;
    }
    a = floor(amount / 2);
    out = fopen("output.bin", "wb");
    fwrite(&a, sizeof(int), 1, out);
    fclose(in);
    fclose(out);
}
