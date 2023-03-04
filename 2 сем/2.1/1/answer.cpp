#include <iostream>
#include <vector>

using namespace std;

typedef struct Time_s {
    int h , m , s;
} Time ;

void printTime(vector<Time> times, int cnt) {
    for (int i = 0; i<cnt; i++)
        printf("%02d:%02d:%02d\n", times[i].h, times[i].m, times[i].s);
}

int main() {
    int count;
    vector<Time> times;

    cin >> count;

    for (int i = 0; i<count; i++){
        Time time;
        cin >> time.h >> time.m >> time.s;
        times.push_back(time);
    }
    printTime(times, count);
    return 0;
}
