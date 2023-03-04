#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int n;
    scanf_s("%d", &n);
    while (n--) {
        int p, q;
        unsigned long long m;
        scanf_s("%d/%d xor %llx", &p, &q, &m);
        double x = (double)p / q;
        unsigned long long* x_bits = (unsigned long long*) & x;
        *x_bits ^= m;
        printf("%0.15g\n", x);
    }
}
