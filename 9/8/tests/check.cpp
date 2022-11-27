#include "binlib.h"
#include <algorithm>

int n, pivot;
vector<int> arr;

void CheckSol(const Bytes &data) {
    if (data.size() != 4 * (n+1))
        THROW("Output size is wrong: %d instead of %d", (int)data.size(), 4*(n+1));
    Stream outs(data);
    int k = outs.read<int>();
    vector<int> res = outs.readArray<int>(n);

    vector<int> sorted = res;
    sort(sorted.begin(), sorted.end());
    sort(arr.begin(), arr.end());
    if (arr != sorted) {
        int pos = -1;
        for (pos = 0; pos < n; pos++)
            if (arr[pos] != sorted[pos])
                break;
        THROW("The set of numbers is wrong: %d-th number must be %d instead of %d", pos, arr[pos], sorted[pos]);
    }

    int leftEq = 0;
    for (int i = 0; i < k; i++) {
        if (arr[i] > pivot)
            THROW("%d-th number in left half is greater than pivot: %d > %d", i, res[i], pivot);
        if (arr[i] == pivot)
            leftEq++;
    }

    int rightEq = 0;
    for (int i = k; i < n; i++) {
        if (arr[i] < pivot)
            THROW("%d-th number in right half is less than pivot: %d < %d", i, res[i], pivot);
        if (arr[i] == pivot)
            rightEq++;
    }

    int diff = abs(leftEq - rightEq);
    if (diff > 1)
        THROW("Bad distribution of elements equal to pivot: %d vs %d", leftEq, rightEq);
}

int main(int argc, char **argv) {
    initChecker(argc, argv);

    Stream ins(inp);
    n = ins.read<int>();
    pivot = ins.read<int>();
    arr = ins.readArray<int>(n);

    SAFESTART()
        CheckSol(ans);
    SAFEEND(JE)
    SAFESTART()
        CheckSol(out);
    SAFEEND(WA)

    fprintf(stderr, "File of size %zd: OK\n", out.size());
    return OK;
}
