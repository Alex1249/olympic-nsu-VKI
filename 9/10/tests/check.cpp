#include "binlib.h"

int main(int argc, char **argv) {
    binlibInitChecker(argc, argv);

    SAFESTART()
        Compare(ans, out);
    SAFEEND(WA)

    fprintf(stderr, "File of size %zd: OK\n", out.size());
    return OK;
}
