#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef struct Line_s {
    int chars, letters = 0, lower = 0, upper = 0, digits = 0;
} Line;

void calcLetters(vector<string> arr, int cnt) {
    Line lineStat;

    for (int i = 0; i<cnt; i++){
        for (int j = 0; j<arr[i].length(); j++){

            lineStat.chars = arr[i].length();
            if (65<=arr[i][j] and arr[i][j]<=90) {
                lineStat.upper++;
                lineStat.letters++;
            }
            if(97<=arr[i][j] and arr[i][j]<=122) {
                lineStat.lower++;
                lineStat.letters++;
            }
            if(48<=arr[i][j] and arr[i][j]<=57)
                lineStat.digits++;
        }
        printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n",
               i+1, lineStat.chars, lineStat.letters, lineStat.lower, lineStat.upper, lineStat.digits);
        lineStat = {};
    }

}

int main() {
    vector<string> lines;
    int cnt_lines = 0;
    ifstream input( "input.txt" );
    for(string line; getline( input, line ); cnt_lines++)
        lines.push_back(line);
    calcLetters(lines, cnt_lines);
    return 0;
}
