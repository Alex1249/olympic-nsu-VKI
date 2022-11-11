
#include <iostream>

using namespace std;


long long** create_triangle(int n, long long abs)
{
	long long** array = new long long* [n + 1];

	for (int i = 0 ; i <= n; ++i) {
		array[i] = new long long[i + 1];
	}
	for (int i = 0; i <= n; ++i)
	{
		array[i][0] = 1 % abs;
		array[i][i] = 1 % abs;
	}
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			array[i][j] = (array[i - 1][j - 1] + array[i - 1][j]) % abs;

		}
	}

	return array;
}


int main()
{
	int abs, size;
	int n, k;
	cin >> abs >> size;

	long long** mass = create_triangle(2001, abs);

	for (int i = 0; i < size; ++i) {
		cin >> n >> k;
		if (k < 0 || k > n) {
			cout << "0" << endl;
		} else {
			cout << mass[n][k] << endl;
		}
	}

    return 0;
}