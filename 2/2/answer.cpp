#include <iostream>

using namespace std;


long long unsigned int factorial(int n) {
    long long unsigned int i, x = 1;

    for (i = 1; i <= n; i++) x *= i;

    return x;
}

int main() {
    int i, n, c;
    cin >> n;

    for (i = 0; i < n + 1; i++) {
        long long unsigned int ii = factorial(i);

        for (c = 0; c <= i; c++) {
            cout << ii / (factorial(c) * factorial(i - c)) << " ";
        }

        cout << "\n";
    }

    return 0;
}