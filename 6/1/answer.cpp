#include <iostream>
using namespace std;

int binary_search(int* a, int x, int n)
{
	int left = 0;
	int right = n - 1;
	int middle;

	do
	{
		middle = (left + right) / 2;
        if (x == a[middle]) return middle;
        else if (a[middle] < x) left = middle + 1;
        else right = middle - 1;
	} while (left <= right);

	return -1;
}

int main() {
	int N, x, i = 0;
	cin >> N >> x;
	int* a = new int[N];

	while (i < N) {
		cin >> a[i];
		i++;
	}

	cout << binary_search(a, x, N);

	return 0;
}
