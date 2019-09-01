#include "stdio.h"

int main() {
    int c, nw;

    nw = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == ' ' || c == '\n') {
            nw++;
        }
    }

    printf("%d\n", nw);
}
