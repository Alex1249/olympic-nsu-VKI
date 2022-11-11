#include <iostream>

using namespace std;


void shake_sort(int* a, int n) {
	int i, x, left = 0, right = n-1;
	bool f;
	f = true;
	while (f){
		f = false;
		i = left;
		while (i < right) {
			if (a[i] > a[i + 1]) {
				x = a[i];
				a[i] = a[i + 1];
				a[i + 1] = x;
				f = true;
			}
			i++;
		}
		right--;
		if (f) {
			f = false;
			i = right;
			while (i > left) {
				if (a[i] < a[i - 1]) {
					x = a[i];
					a[i] = a[i - 1];
					a[i - 1] = x;
					f = true;
				}
				i--;
			}
		}
		left++;
	}
}

int main() {
	int n;
	cin >> n;

	int* a = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

	shake_sort(a, n);
	cout << '\n';

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}
