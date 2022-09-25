#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <string.h>

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

int main()
{
	string str;
	int b;
	int kolvo;
	cin >> b;
	cin >> kolvo;
	cin >> str;
	double vremen = 0;
	int count = -1;
	double rez = 0;
	for (int i = 1; i < str.length(); i++)
	{
		int n = get(str[i]);
		double vals;
		vals = n * pow(b, count);
		rez += vals;
		count--;
	}

	string OUTP = to_string(rez);
	int itog = get(OUTP[OUTP.length() - 1]);
	OUTP.erase(OUTP.length() - 1, 1);
	if (itog >= 5)
	{
		OUTP[OUTP.length() - 1] = get_char(get(OUTP[OUTP.length() - 1]) + 1);
	}
	if (OUTP.empty()) cout << 0;
	cout << OUTP;
	return 0;
}
