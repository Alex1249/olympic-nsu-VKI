#include <cstdio>

using namespace std;


double bci2(int n, int k) {
    if (k > n / 2) {
        k = n - k; // возьмем минимальное из k, n-k.. В силу симметричность C(n,k)=C(n,n-k)
    }

    if (k == 1) return n;
    else if (k == 0) return 1;

    double r = 1;
    for (int i = 1; i <= k; ++i) {
        if ((int)r % 2 == 0) {
            r /= i;
            r *= n - i + 1;
        } else {
            r *= n - i + 1;
            r /= i;
        }
    }

    return r;
}


int main() {
    int n;
    scanf_s("%d", &n);

    for (int k = 1; k <= n; k++) {
        int b, l;
        scanf_s("%d %d", &b, &l);
        printf("%0.10g\n",bci2(b, l));
    }

    return 0;
}
