using namespace std;
#include <iostream>
#include <fstream>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int rev(int from);

int main() {
	int quantity, amount = 0, byte;
	bool flag = true;
	ifstream inp;
	inp.open("input.bin", ios::binary | ios::in);
	inp.read((char*)&quantity, sizeof(int));
	if (quantity >= 1 && quantity <= 10000) flag = true;
	else {
		flag = false;
		quantity = rev(quantity);
	}
	for (int i = 0; i < quantity; i++) {
		inp.read((char*)&byte, sizeof(int));
		if (!flag) byte = rev(byte);
		amount += byte;
	}
	ofstream outp;
	if (!flag) amount = rev(amount);
	outp.open("output.bin", ios::binary | ios::out);
	outp.write((char*)&amount, sizeof(int));
	inp.close();
	outp.close();
}

int rev(int a) {
	int t;
	char* f_byte = (char*)&a;
	char* t_byte = (char*)&t;
	t_byte[0] = f_byte[3];
	t_byte[1] = f_byte[2];
	t_byte[2] = f_byte[1];
	t_byte[3] = f_byte[0];
	return t;
}
