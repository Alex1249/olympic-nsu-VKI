#include <iostream>
#include <iomanip>
#include <bitset>
#include <limits>
#include <math.h>
using namespace std;

int main() {
    int num;
    cin >> num;
    int n = 32;
    int l = num;
    cout << bitset<sizeof(num)* CHAR_BIT>(num)<<endl;
    long long unsigned int count = 0;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x <<= 1;
        x |= 1 & num;
        num >>= 1;
    }
    cout << x << endl;
    for (int i = 0; i < n; i++)
    {
        x = ((l >> i) & 1);
        cout << x;
    }
    return 0;
}
