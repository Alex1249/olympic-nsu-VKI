#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<string> arr, int n){
    for(int i = 0; i<n; i++){
        for(int j = arr[i].length()-1; j>=0; j--){
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> arr;
    for (int i = 0; i<n; i++){
        string s;
        cin >> s;
        arr.push_back(s);
    }
    reverse(arr, n);
    return 0;
}
