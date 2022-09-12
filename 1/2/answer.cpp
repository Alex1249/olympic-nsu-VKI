#include <cstdio>

int isPrime(int n){
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        if (isPrime(i)) printf("%d ", i);
}

// Written with love.By Alexey Kuznetsov.