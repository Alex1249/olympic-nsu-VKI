#include <iostream>

using namespace std;

int readTime ( char * iStr , int * oHours , int * oMinutes , int * oSeconds ){
    int h = 0, m = 0, s = 0;
    int match = sscanf(iStr,"%d:%d:%d", &h, &m, &s);
    if (match > 1 and h < 24 and m < 60 and s < 60){
        *oHours = h;
        *oSeconds = s;
        *oMinutes = m;
        return 1;
    }
    else{
        *oHours = -1;
        *oSeconds = -1;
        *oMinutes = -1;
        return 0;
    }
}
 
int main() {
    int h = 0, m = 0, s = 0;
    char iTime[15];
    scanf("%s", iTime);
    int result = readTime(iTime, &h, &m, &s);
    cout << result << " " << h << " " << m << " " << s << endl
        << result << " " << h << " " << m << endl
        << result << " " << h;
    return 0;
}
