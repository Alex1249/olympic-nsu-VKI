#include <iostream>

using namespace std;


int isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int q = 0, n = 0, x = 0;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> x;
        if (isPrime(x)) cout << x << " prime" << endl;
        else cout << x << " not" << endl;
    }
    return 0;
}

// Written with love.By Alexey Kuznetsov
