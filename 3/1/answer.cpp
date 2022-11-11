#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


char get(int n) {
  if (n < 10) {
      return (char)(n + '0');
  } else {
      return (char)(n + 87);
  }
}

string CTTsd(int n, int base) {
    string out = "";
    while(n > 0) {
        out += get(n % base);
        n /= base;
    }

    return out;
}


int main() {
  int n, b;
  cin >> b >> n;

  string out = CTTsd(n,b);
  reverse(out.begin(), out.end());

  if (out.empty()) cout << 0;
  cout << out;

  return 0;
} 
