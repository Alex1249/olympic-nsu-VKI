#include <iostream>
using namespace std;

int binarsearch(int* a, int x, int n)
{
	int left = 0;
	int right = n - 1;
	int middle;
	do
	{
		middle = (left + right) / 2;
		if (x == a[middle])
			return middle;
		else
			if (a[middle] < x)
				left = middle + 1;
			else right = middle - 1;
	} while (left <= right);
	return -1;
}

int main() {
	int inp, x, i = 0;
	cin >> inp >> x;
	int* a = new int[inp];
	while (i < inp) {
		cin >> a[i];
		i++;
	}
	cout << binarsearch(a, x, inp);
	return 0;
}
