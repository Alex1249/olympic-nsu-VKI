using namespace std;
#include <fstream>
#include <iostream>

int chapter(int* a, int n, int kernel);

int main() {
    int arr_count = 0, kernel = 0;
    ifstream inp;
    inp.open("input.bin", std::ios::binary);
    inp.read((char*)&arr_count, sizeof(int));
    inp.read((char*)&kernel, sizeof(int));
    int* inp_d = new int[arr_count];
    for (int i = 0; i < arr_count; ++i) 
        inp.read((char*)&inp_d[i], sizeof(int));
    const int result = chapter(inp_d, arr_count, kernel);
    ofstream outp;
    outp.open("output.bin", std::ios::binary);
    outp.write((const char*)&result, sizeof(int));
    for (int i = 0; i < arr_count; ++i) 
        outp.write((const char*)&inp_d[i], sizeof(int));
    inp.close();
    outp.close();
}

int chapter(int* inp_d, int arr_count, int kernel) {
    int* temp = new int[arr_count];
    int start = 0, end = arr_count - 1, c_l = 0, left{}, right{};
    for (int i = 0; i < arr_count; ++i) {
        if (inp_d[i] < kernel) {
            c_l++;
            temp[start++] = inp_d[i];
        } else if (inp_d[i] > kernel)
            temp[end--] = inp_d[i];
        else {
            if (left < right) {
                left++;
                c_l++;
                temp[start++] = inp_d[i];
            } else {
                right++;
                temp[end--] = inp_d[i];
            }
        }
    }
    for (int i = 0; i < arr_count; ++i) inp_d[i] = temp[i];
    return c_l;
}
