#include <iostream>
using namespace std;
void ins_sort(int* a, int n) {
	int e, x, r;
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
	int n, i = 0;
	cin >> n;
	int* a = new int[n];
	while (i < n) {
		cin >> a[i];
		i++;
	}
	ins_sort(a, n);
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
