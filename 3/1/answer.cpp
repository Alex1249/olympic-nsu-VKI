#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string OUTPUT = "";


char get(int n)
{
  if(n < 10)
    return n + '0';
  else
    return n + 87;
}

void CTTsd(int n, int base) {

  while(n>0){
    OUTPUT+=get(n%base);
    n=n/base;
  }
}


int main()
{
  int n;
  int b;
  cin >> b;
  cin >> n;
  CTTsd(n,b);
  string OUTREV = OUTPUT;
  reverse(OUTREV.begin(), OUTREV.end());
  if(OUTREV.empty()) cout<< 0;
  cout<<OUTREV;
  return 0;
} 
