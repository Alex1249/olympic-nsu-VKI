#include <iostream>

using namespace std;


void select_sort(int* a, int n) {
	int x, r;
	for (int i = 0; i < n - 1; i++) {
		r = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[r]) {
				r = j;
			}
		}
		if (i != r) {
			x = a[i];
			a[i] = a[r];
			a[r] = x;
		}
	}
}

int main() {
	int n;
	cin >> n;

	int* a = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

	select_sort(a, n);
	cout << '\n';

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}
