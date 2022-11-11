#include <iostream>
#include <algorithm>

using namespace std;


void start21(int a[], int n) {
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] < a[i + 1]) {
			int min = i + 1;
			for (int j = i + 2; j < n; j++) {
                if (a[j] > a[i] && a[j] < a[min]) min = j;
            }
			swap(a[i], a[min]);
			reverse(a + i + 1, a + n);
			break;
		}
		if (i == 0) reverse(a + i, a + n);
	}

	for (int i = 0; i < n; i++) cout << a[i] << " ";
}


int main() {
	int N;
	cin >> N;
	int* m = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}
	start21(m, N);

	return 0;
}
