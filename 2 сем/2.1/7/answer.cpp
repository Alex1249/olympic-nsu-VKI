#include <iostream>
#include <regex>

using namespace std;

int main() {
    string s;
    int n = 0;
    cin >> s;
    vector<string> strs;
    const regex r(R"(\w+)");
    for(sregex_iterator i = sregex_iterator(s.begin(), s.end(), r);
        i != sregex_iterator();
        i++, n++)
    {
        smatch m = *i;
        strs.push_back(m.str());
    }
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << strs[i] << endl;
    return 0;
}
