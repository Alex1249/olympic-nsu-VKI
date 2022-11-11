#include <iostream>

using namespace std;


long long int arr[70][70];

int main() {
    for (int n = 0; n < 70; n++) {
        for (int k = 0; k < 70; k++) {
            if (k == 0 || n == k) {
                arr[n][k] = 1;
            } else {
                arr[n][k] = arr[n - 1][k - 1] + arr[n - 1][k];
            }
        }
    }

    int n = 0;
    cin >> n;

    for (int k = 0; n >= k; k++) {
        for (int m = 0; k >= m; m++) {
            cout << arr[k][m] << " ";
        }
        cout << "\n";
    }

    return 0;
}
