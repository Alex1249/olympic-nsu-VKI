using namespace std;
#include <iostream>
#include <string>
#include <fstream>

int main() {
    string ln;
    ifstream inp("input.txt");
    int i = 0;
    if (inp.is_open()) {
        while (getline(inp, ln)) {
            i++;
            cout << ln << " " << i << endl;
        }
    }
    ofstream outp;
    outp.open("output.txt");
    if (outp.is_open())
        outp << i << endl;
    inp.close();
    outp.close();
}
