#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

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

int getinten(char* n, int b) {
    int e = 0, r = 0, r1 = 0, j = 0;;
    for (int i = strlen(n) - 1; i >= 0; i--) {
        r += get(n[i]) * pow(b, e);
        e++;
    }
    return r;
}

void baza(int n, int b) {
    while (n > 0) {
        OUTPUT += get_char(n % b);
        n = n / b;
    }
}

int main(){
    int b, k, a;
    char n[52];
    cin >> b;
    cin >> k;
    cin >> n;
    a = getinten(n, b);
    baza(a, k);

    string out = OUTPUT;
    reverse(out.begin(), out.end());

    if (out.empty()) cout << 0;
    cout << out;

    return 0;
}
