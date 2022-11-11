#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;


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


string CTTsd(string str, int base) {


    string out = "";

    int rez = 0, count = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        int n = get(str[i]);
        int value = n * pow(base, count);
        rez += value;
        count++;
    }

    int tw = rez;
    while (tw > 0) {
        int value = tw % 10;
        out += get_char(value);
        tw = tw / 10;
    }

    return out;
}


int main()
{
    int b;
    string n = "";
    cin >> b;
    cin >> n;

    string output = CTTsd(n, b);
    reverse(output.begin(), output.end());

    if (output.empty()) cout << 0;
    cout << output;

    return 0;
}
