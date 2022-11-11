#include <iostream>
#include <cmath>

using namespace std;


bool simpleNumbers(int N) {
	if (N <= 1) return false;

	bool isSimple = true;
	for (int i = 2; i <= sqrt(N); i++) {
		if (N % i == 0) {
			isSimple = false;
			break;
		}
	}
	return isSimple;
}


int main() {
	int N = 0;
	cin >> N;

    for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		for (int j = 0; j <= 16; j++) {
			int step = pow(2, i);
			int to_del = val / step;
			if (to_del > 1000) {
				if (simpleNumbers(to_del)) {
					cout << step << endl;
					break;
				}
			}
		}
	}

    return 0;
}
