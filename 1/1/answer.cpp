#include <cstdio>

int isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    scanf_s("%d", &n);
    printf(isPrime(n) ? "YES" : "NO");
    return 0;
}

// Written with love.By Alexey Kuznetsov.