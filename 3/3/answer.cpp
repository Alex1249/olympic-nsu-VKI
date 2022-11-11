#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

string OUTPUT = "";


int get(char n) {
    if (n < 87) {
        return n - '0';
    }
    else {
        return n - 87;
    }
}


char get_char(int n) {
    if (n < 10) {
        return (char)(n + '0');
    } else {
        return (char)(n + 87);
    }
}

void CTTsd(std::string str, int base, int kolvo) {
    int count = -1;
    int rez = 0;

    for (int i = 2; i < str.length(); i++) {
        int n = get(str[i]);
        int value = 0;
        value = n * pow(base, count);
        rez += value;
        count--;
    }
}


int main() {
    double n;
    int b;
    int kolvo;
    cin >> b;
    cin >> kolvo;
    cin >> n;
    double value = n;
    double vremen = 0;
    for (int i = 0; i < kolvo; i++) {
        if (i == 0) {
            vremen = value * b;
        } else {
            vremen = vremen * b;
        }

        if (vremen >= 1) {
            int val = (int)vremen % 1000;
            if (vremen - val >= 0.98) {
                val += 1;
            }
            OUTPUT += get_char(val);
            vremen -= val;
        } else {
            OUTPUT += '0';
        }

    }

    for (int i = OUTPUT.length() - 1; i >= 0; i--) {
        if (OUTPUT[i] != '0') {
            break;
        } else {
            OUTPUT.erase(i, 1);
        }
    }

    /*CTTsd(n, b, kolvo);*/
    string OUTREV = "0." + OUTPUT;
    /*reverse(OUTREV.begin(), OUTREV.end());*/

    if (OUTREV.empty()) cout << 0;
    cout << OUTREV;

    return 0;
}
