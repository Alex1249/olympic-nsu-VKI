#include <iostream>
using namespace std;

void ins_sort(int* a, int n) {
	int j = 0, e, x;
	for (int i = 0; i < n; i++) {
		x = a[i];
		j = i - 1;
		while (j >= 0 && a[j] >= x) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = x;
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
