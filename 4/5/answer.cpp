#include <iostream>
#include <bitset>

using namespace std;


bitset<32>* arr = new bitset<32>;


// инициализирует массив битов длины num, устанавливая все его биты в ноль
void createArr(int num) {
	arr = new bitset<32>[num];
}


// устанавливает значение idx-ого бита в nValue (newValue) (которое равно 0 или 1)
void bitsetSet(int idx, int nValue) {
	int more = idx / 32; // обработка больше 32
	if (more != 0)
	{
		idx -= more * 32;
	}
	arr[more].set(31 - idx, nValue);
}

int main() {
	int n, m, nValue, idx;
	cin >> n >> m;
	createArr(n);
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		cin >> t;
		arr[i] = bitset<32>(t);
	}
	for (int j = 0; j < m; j++) {
		cin >> nValue >> idx;
		bitsetSet(idx, nValue);
	}

	for (int i = 0; i < n; i++){
		int value = (int)arr[i].to_ullong();
		cout << value << " ";
	}

	free(arr);
	return 0;
}
