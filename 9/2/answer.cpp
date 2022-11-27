#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    FILE* inp = fopen("input.txt", "r");
    char ch;
    int a, d, b = 0, c = 0, i = 0, j = 0, word = 0;
    int* arr = new int[100000];
    while (!feof(inp)) {
        fscanf_s(inp, "%c", &ch);
        d = int(ch);
        if (d != 32 && d != 10 && d != 9 && d != 11) {
            if (c == 0) {
                c++;
                word++;
            }
            b++;
            arr[j] = b;
        } else if (d <= 32 && c != 0) {
            c = 0;
            b = 0;
            j++;
        } else b = 0;
    }
    for (i = 1; i < word; i++) {
        a = arr[i];
        c = i - 1;
        while (a < arr[c] && c >= 0) {
            arr[c + 1] = arr[c];
            --c;
        }
        arr[c + 1] = a;
    }
    i = 1;
    while (word > 0) {
        b = 1;
        while (arr[i] == arr[i - 1]) {
            b++;
            i++;
            word--;
        }
        cout << arr[i - 1] << " - " << b << "\n";
        i++;
        word--;
    }
    fclose(inp);
}
