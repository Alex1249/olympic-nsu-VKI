#include <iostream>
#include <vector>

using namespace std;

typedef struct Label_s {
    char name[15];
    int age;
} Label;

typedef struct NameStats_s {
    int cntTotal;
    int cntLong = 0;
} NameStats ;

typedef struct AgeStats_s {
    int cntTotal;
    int cntAdults = 0;
    int cntKids = 0;
} AgeStats ;

void calcStats (vector<Label> arr, int cnt , NameStats * oNames , AgeStats * oAges ){
    for (int i = 0; i<cnt; i++){
        string name = arr[i].name;
        if (name.length() > 10)
            oNames->cntLong += 1;
        if (arr[i].age>17)
            oAges->cntAdults += 1;
        else if (arr[i].age<14)
            oAges->cntKids += 1;
    }
}

int main() {
    int n;
    vector<Label> labels;
    NameStats n_stats;
    AgeStats  a_stats;

    cin >> n;

    n_stats.cntTotal = n;
    a_stats.cntTotal = n;

    for (int i = 0; i<n; i++){
        Label label;
        scanf("%s %d let", label.name, &label.age);
        labels.push_back(label);
    }
    calcStats(labels, n, &n_stats, &a_stats);
    cout << "names: total = " << n << endl
        << "names: long = " << n_stats.cntLong << endl
        << "ages: total = " << n << endl
        << "ages: adult = " << a_stats.cntAdults << endl
        << "ages: kid = " << a_stats.cntKids;
    return 0;
}

