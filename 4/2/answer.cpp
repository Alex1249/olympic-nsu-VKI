#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;


int main() {
    int num;
    cin >> num;

    cout << bitset<sizeof(num)* CHAR_BIT>(num) << endl;

    int x = 0, n = 32, l = num;
    for (int i = 0; i < n; i++) {
        x <<= 1;
        x |= 1 & num;
        num >>= 1;
    }
    cout << x << endl;

    for (int i = 0; i < n; i++) {
        x = ((l >> i) & 1);
        cout << x;
    }

    return 0;
}
