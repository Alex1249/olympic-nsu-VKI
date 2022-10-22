#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
int a[100000];

int* pdsa(int* first, int* last, int value)
{
    int* b;
    int count = last - first, step;
    while (count > 0)
    {
        b = first;
        step = count / 2;
        b += step;
        if (!(value < *b))
        {
            first = ++b;
            count -= step + 1;
        }
        else
            count = step;
    }
    return first;
}

int main()
{
    int N, Q, X, R = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> a[i];
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        cin >> X;
        X += R;
        int* f = pdsa(a, a + N, X);
        if (*(f - 1) != X) R = -1; else R = f - 1 - a;
        cout << endl << R;
    }
    return 0;
}
