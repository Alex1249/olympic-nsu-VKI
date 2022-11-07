#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <sstream>
using namespace std;

void ins_sort(int* mas, int size) {
int i = 0;
int j = size - 1;
int mid = mas[size / 2];
do {
while (mas[i] < mid) {
i++;
}
while (mas[j] > mid) {
j--;
}
if (i <= j) {
int tmp = mas[i];
mas[i] = mas[j];
mas[j] = tmp;

i++;
j--;
}
} while (i <= j);
if (j > 0) {
ins_sort(mas, j + 1);
}
if (i < size) {
ins_sort(&mas[i], size - i);
}
}

int work_1() {
int N;
scanf("%d", &N);
int* list = new int[N];
for (int i = 0; i < N; i++) {
scanf("%d", &list[i]);
}
ins_sort(list, N);
for (int i = 0; i < N; i++) {
printf("%d ", list[i]);
}
return 0;
}

int main() {
srand((unsigned)time(NULL));
setlocale(LC_ALL, "Russian");
work_1();
printf("\n\n\n");
return 0;
}
