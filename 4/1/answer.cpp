#include <iostream>
#include <bitset>
#include <limits>

using namespace std;


int main() {
    int num;
    cin >> num;

    bitset<numeric_limits<unsigned long>::digits> bits(num);

    int n = 32, max = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        if ((int)bits[i] != 0) {
            temp++;
        } else {
            if (max < temp) {
                max = temp;
            }
            temp = 0;
        }
    }

    if (max < temp) {
        max = temp;
    }

    cout << max;
}
