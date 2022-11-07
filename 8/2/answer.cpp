#include <iostream>

using namespace std;

void pyr_create(int arr[], int n, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[max])
        max = left;
    if (right < n && arr[right] > arr[max])
        max = right;
    if (max != i) {
        swap(arr[i], arr[max]);
        pyr_create(arr, n, max);
    }
}

void pyr_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        pyr_create(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        pyr_create(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pyr_sort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
