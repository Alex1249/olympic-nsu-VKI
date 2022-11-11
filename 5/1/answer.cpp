#include <iostream>

using namespace std;


void permut_to_invtabs(const int* a, int* b, int n) {
    int z, i, j, h, count;
    h = 1;
    for (z = 0; z < n; z++) {
        for (i = 0; i < n; i++) {
            if (a[i] == h) {
                count = 0;
                for (j = 0; j < i; j++) {
                    if (a[j] > h) count++;
                }

                b[h - 1] = count;
                h++;
            }
        }
    }
}

int main() {
    int n, i, a[1000], b[1000];
    cin >> n;

    for (i = 0; i < n; i++)
        cin >> a[i];

    permut_to_invtabs(&a[0], &b[0], n);

    for (i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}
