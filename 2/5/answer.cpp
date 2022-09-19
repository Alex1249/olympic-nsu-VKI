
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
long long** create_tringle(int n, long long modul)
{
	long long** mass = new long long* [n + 1];
	for (int i = 0 ; i <= n; ++i)
	{
		mass[i] = new long long[i + 1];
	}
	for (int i = 0; i <= n; ++i)
	{
		mass[i][0] = 1 % modul;
		mass[i][i] = 1 % modul;
	}
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			mass[i][j] = (mass[i - 1][j - 1] + mass[i - 1][j]) % modul;

		}
	}
	return mass;
}
int main()
{
	int modul = 0;
	int size = 0;
	int n = 0;
	int k = 0;
	cin >> modul >> size;
	long long** mass = create_tringle(2001, modul);
	for (int i = 0; i < size; ++i)
	{
		cin >> n >> k;
		if (k<0 || k>n)
		{
			cout << "0" << endl;
		}
		else
		{
			cout << mass[n][k] << endl;
		}
	}
}