#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

string OUTPUT = "";


int get(char n)
{
    if (n < 87)
        return n - '0';
    else
        return n - 87;
}

char get_char(int n)
{
    if (n < 10)
        return n + '0';
    else
        return n + 87;
}
void CTTsd(std::string str, int base) {
    int count = 0;
    int rez = 0;
    for (int i = str.length()-1; i >= 0; i--)
    {
        int n = get(str[i]);
        int value = 0;
        value = n * pow(base, count);
        rez += value;
        count++;
    }
    int tw = rez;
    while (tw > 0) {
        int value = tw % 10;
        OUTPUT += get_char(value);
        tw = tw / 10;
    }
    
}


int main()
{
    string n = "";
    int b;
    cin >> b;
    cin >> n;
    CTTsd(n, b);
    string OUTREV = OUTPUT;
    reverse(OUTREV.begin(), OUTREV.end());
    if (OUTREV.empty()) cout << 0;
    cout << OUTREV;
    return 0;
}
