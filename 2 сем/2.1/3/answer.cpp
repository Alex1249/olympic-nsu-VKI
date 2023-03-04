#include <iostream>
#include <vector>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef struct DateTime_s {
int year , month , day ;
int hours , minutes , seconds ;
} DateTime ;
 
DateTime min (vector<DateTime> arr , int cnt ){
    vector<unsigned long long> dates;
 
    for (int i = 0; i<cnt; i++) {
        char buf[15];
        unsigned long long date;
 
        snprintf(buf, sizeof(buf), "%d%02d%02d%02d%02d%02d", arr[i].year,
                           arr[i].month, arr[i].day, arr[i].hours, arr[i].minutes, arr[i].seconds);
        string str = buf;
 
        istringstream (str) >> date;
        dates.push_back(date);
    }
 
    int min_index = distance(begin(dates), min_element(std::begin(dates), end(dates)));
 
    return arr[min_index];
}
 
int main() {
    int n;
    vector<DateTime> arr;
 
    cin >> n;
 
    for (int i = 0; i<n; i++){
        DateTime date;
        scanf("%d %d %d %d %d %d", &date.year, &date.month, &date.day, &date.hours, &date.minutes, &date.seconds);
        arr.push_back(date);
    }
 
    DateTime min_date = min(arr, n);
    printf("%d %d %d %d %d %d", min_date.year,
           min_date.month, min_date.day, min_date.hours, min_date.minutes, min_date.seconds);
    return 0;
}
