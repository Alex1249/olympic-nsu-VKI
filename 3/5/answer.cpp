#include <iostream>
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
