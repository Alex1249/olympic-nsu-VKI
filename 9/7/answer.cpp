#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;


void merge(const int* a, int ak, const int* b, int bk, int* r) {
	int i = 0, j = 0, k = 0, x;
	while ((i < ak) || (j < bk)) {
		if (i == ak)
			x = b[j++];
		else if (j == bk)
			x = a[i++];
		else if (a[i] < b[j])
			x = a[i++];
		else x = b[j++];
		r[k++] = x;
	}
}
int main() {
	long signed N = 0, M = 0;
	FILE* in = NULL;
	FILE* out = NULL;

	in = fopen("input.bin", "rb");
	out = fopen("output.bin", "wb");
	fread(&N, sizeof(int), 1, in);
	fread(&M, sizeof(int), 1, in);

	int* a = new int[N]();
	int* b = new int[M]();

	int* r = new int[N + M]();

	for (int i = 0; i < N; i++)
		fread(&a[i], sizeof(int), 1, in);
	for (int i = 0; i < M; i++)
		fread(&b[i], sizeof(int), 1, in);

	merge(a, N, b, M, r);
	for (int i = 0; i < N + M; i++) {
		fwrite(&r[i], sizeof(int), 1, out);
	}

	delete[] a;

	delete[] b;

	delete[] r;

	fclose(in);

	fclose(out);
	return 0;
}
