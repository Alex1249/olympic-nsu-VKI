#include <iostream>
using namespace std;

int invtav_permut(const int a[], int b[], int n) {
    for (int i = 1; i <= n; i++) {
        int spaceCount = 0;
        for (int j = 0; j < n; j++) {
            if (b[j] == 0 && spaceCount == a[i - 1]) {
                b[j] = i;
                break;
            }
            if (b[j] == 0) spaceCount++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << b[i]<<" ";
    }
    return 1;
}

int main() {
    int n;
    cin >> n;

    int* a = new int[n];
    int* b = new int[n] { 0 };

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (!invtav_permut(a, b, n)) cout << "NO";
    return 0;
}
