#include <iostream>

using namespace std;


void undstr(string a, string a1, int* b) {
	int sch, p[100001] = { 0 }, x = 0, i = 0, n = a.length(), n1 = a1.length();
	while (i <= n1 - n)
	{
		if (a[n - 1] == a1[i + n - 1])
		{
			sch = n - 1;
			while (sch >= 0 && a[sch] == a1[i + sch]) {
				sch--;
			}
			if (sch == -1) {
				p[x] = i;
				x++;
			}
		}
		i += b[a1[i + (n - 1)]];
	}
	cout << x << "\n";
	for (int i = 0; i <= x - 1; i++) {
		cout << p[i] << "\n";
	}
}


int main() {
	string a = "", a1 = "";
    cin >> a1;
    cin >> a;

    int b[256] = { 0 }, h = 1;

	int n = a.length();
	for (int & i : b) {
		i = n;
	}

	for (int i = n - 2; i >= 0; i--) {
		if (b[a[i]] == n) {
			b[a[i]] = h;
		}
		h++;
	}
	undstr(a, a1, b);

    return 0;
}
