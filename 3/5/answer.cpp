#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string OUTPUT = "";

char getsch(int n)
{
    if (tolower(n) < 10)
        return tolower(n) + '0';
    else
        return tolower(n) + 87;
}
char getschinv(char n)
{
    if (tolower(n) < 87)
        return tolower(n) - '0';
    else
        return tolower(n) - 87;
}

int getinten(char* n, int b) {
    int e = 0, r = 0, r1 = 0, j = 0;;
    for (int i = strlen(n) - 1; i >= 0; i--) {
        r += getschinv(n[i]) * pow(b, e);
        e++;
    }
    return r;
}


void perevod(char* n, int b) {
    int a = 0, e = 0;
    for (int i = strlen(n) - 1; i >= 0; i--) {
        a += (n[i] - 48) * pow(10, e);
        e++;
    }
    while (a > 0) {
        OUTPUT += getsch(a % b);
        a = a / b;
    }
}

void drob(char* n, int b, int k) {
    int drobi = 0, i = 0, e = 0, g = 0;
    while (i < strlen(n)) {
        if (n[i] == '.') {
            for (int j = strlen(n) - 1; j > i; j--) {
                drobi += (n[j] - 48) * pow(10, e);
                e++;
            }
            break;
        }
        i++;
    }
    e = pow(10, e);
    OUTPUT += "0.";
    while (g < k) {
        if (drobi < e) {
            drobi *= b;
        }
        OUTPUT += getsch((drobi / e) % b);
        if (drobi > e) {
            drobi %= e;
        }
        if (drobi == e) {
            break;
        }
        g += 1;
    }
}

void drob2(char* n, int b) {
    int i = 0, e = 0, g = 0, r = 0, das[6], drobi321;
    double drobi = 0;
    while (i < strlen(n)) {
        if (n[i] == '.') {
            for (int j = strlen(n) - 1; j > i; j--) {
                drobi += getschinv(n[j]) * pow(b, -(j-1));
                e++;
            }
            break;
        }
        i++;
    }
    drobi321 = int(drobi * pow(10, 6));
    if (drobi321 % 10 >= 5) drobi321 = (drobi321 / 10) + 1;
    else drobi321 /= 10;
    for (int j = 4; j >= 0; j--) {
        das[j] = getsch(drobi321 % 10);
        drobi321 /= 10;
    }
    OUTPUT += "0.";
    for (int j = 0; j <= 4; j++) {
        OUTPUT += das[j];
    }
}


void baza(int n, int b) {

    while (n > 0) {
        OUTPUT += getsch(n % b);
        n = n / b;
    }
}

int main()
{
    int b, k, a, i = 0;
    char n[52];
    int n1[50];
    cin >> b;
    cin >> k;
    cin >> n;
    a = getinten(n, b);
    baza(a, k);
    
    //drob2(n, b);
    string out = OUTPUT;
    reverse(out.begin(), out.end());
    if (out.empty()) cout << 0;
    cout << out;
    return 0;
}
