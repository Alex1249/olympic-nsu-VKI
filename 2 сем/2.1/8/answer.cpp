#include <iostream>
#include <vector>

using namespace std;

void concat(string *pref ,string *suff){
    *pref += *suff;
}

int main() {
    int n;
    cin >> n;
    string concat_s = "";
    vector<string> array;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        array.push_back(s);
    }
    for(int i = 0; i < n; i++){
        concat(&concat_s, &array[i]);
    }
    cout << concat_s;
    return 0;
}
