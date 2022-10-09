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
    std::bitset<std::numeric_limits<unsigned long>::digits> bits(num);
    int max = 0;
    int vremenno = 0;
    for (int i = 0; i < n; i++)
    {
        int value = (int)bits[i];
        if ((int)bits[i] != 0)
        {
            vremenno++;
        }
        else
        {
            if (max < vremenno)
            {
                max = vremenno;
            }
            vremenno = 0;
        }
    }
    if (max < vremenno)
    {
        max = vremenno;
        vremenno = 0;
    }
    cout << max;
}
