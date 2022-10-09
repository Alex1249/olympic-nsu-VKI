#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>

using namespace std;
bitset<32>* arr = new bitset<32>;

//инициализирует массив битов длины num, устанавливая все его биты в ноль
void bitsetZero(int num)
{
	arr = new bitset<32>[num/16+1];
}


//возвращает значение idx-ого бита (0 или 1)
int bitsetGet(int idx)
{
	int more = idx / 32;
	if (more > 0)
	{
		idx -= more * 32;
	}
	return arr[more].test(idx); // .test Вернет 0 или 1
}


//устанавливает значение idx-ого бита в newval (которое равно 0 или 1)
void bitsetSet(int idx, int newval)
{
	int more = idx / 32; //обработка больше 32
	if (more != 0)
	{
		idx -= more * 32;
	}
	arr[more].set(idx, newval);
}

//возвращает 1, если среди битов с номерами k
//для left <= k < right есть единичный, и 0 иначе
int bitsetAny(int left, int right)
{
	//Если единичный бит на отрезке есть, то надо
	//вывести some, а если нет — то none.
	int maxright = right / 32; //Если больше 32
	int maxleft = left / 32; //Если больше 32
	right -= maxright * 32;
	left -= maxleft * 32;

	for (int i = maxleft; i <= maxright; i++)
	{
		int j = 0, n = 32;
		if (i == maxleft)
		{
			j = left;
		}
		if (i == maxright)
		{
			n = right;
		}
		while (j < n)
		{
			if (arr[i] == 0)
			{
				break;
			}
			if (arr[i].test(j))
			{
				return 1; // Если есть 1
			}
			j++;
		}
	}
	return 0;
}
int main()
{
	int kolvo;
	cin >> kolvo;
	for (int i = 0; i < kolvo; i++)
	{
		int val1,val2, t;
		cin >> t >> val1;
		switch (t)
		{
			case 0:
				delete[] arr;
				bitsetZero(val1);
				break;
			case 1:
				cout << bitsetGet(val1) << endl;
				break;
			case 2:
				int newval;
				cin  >> newval;
				bitsetSet(val1, newval);
				break;
			case 3:
				cin >> val2;
				if (bitsetAny(val1, val2))
				{
					cout << "some" << endl;
				}
				else
				{
					cout << "none" << endl;
				}
				break;
		}
	}
	return 0;
}
