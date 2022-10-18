#include <stdio.h>
#include <stdbool.h>

int isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int q, n, x;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);
        printf(isPrime(x) ? "%d prime\n" : "%d not\n", x);
    }
    return 0;
}

//
// Created by letovsk1y on 9/12/2022.
//
