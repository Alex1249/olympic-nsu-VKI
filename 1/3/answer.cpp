#include <vector>
#include <iostream>

using namespace std;


int main(){
    int n;
    std::vector<int> arr;

    cin >> n;

    for (int i = 0; i <= n; i++)
        arr.push_back(i);

    for (int i = 2; i * i <= n+1; i++)
    {
        if (arr[i])
            for (int j = i * i; j <= n; j += i)
                arr[j] = 0;
    }
    for (int i = 2; i < n+1; i++) {
        if (arr[i]) {
            cout << arr[i] << ' ';
        }
    }
    return 0;
}
// Written with love.By Alexey Kuznetsov