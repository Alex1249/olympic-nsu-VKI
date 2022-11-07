#include <iostream>
using namespace std;
void ins_sort(int* a, int n) {
    int count, j;
    int tmp;
    for (count = n / 2; count > 0; count /= 2)
        for (int i = count; i < n; i++)
        {
            tmp = a[i];
            for (j = i; j >= count; j -= count)
            {
                if (tmp < a[j - count])
                    a[j] = a[j - count];
                else
                    break;
            }
            a[j] = tmp;
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
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
