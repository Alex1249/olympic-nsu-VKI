#include <iostream>
using namespace std;

void f(float* a, int n, int x)
{
	int b, c, d;
	b = 0;
	c = n - 1;
	while (1 < (c - b))
	{
		d = (c + b) / 2;
		if (a[d] < x) b = d;
		else c = d;
	}
	if (x - a[b] <= a[c] - x) cout << b;
	else cout << c;
}

int main()
{
	int n, x, c;
	float* a;
	cin >> n >> x;
	a = (float*)malloc(sizeof(float) * n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	f(a, n, x);
	free(a);
	return 0;
}
