#include "stdio.h"

#define MAX_CHAR  128
#define MAX_STAR  20

int main() {

    int c;
    int cc[MAX_CHAR];

    for (int i = 0; i < MAX_CHAR; i++) {
        cc[i] = 0;
    }

    int max = 0;
    while ((c = getchar()) != EOF) {
        if (c < MAX_CHAR) {
            cc[c]++;
            if (cc[c] > max) {
                max = cc[c];
            }
        }
    }

    for (int i = 0; i < MAX_CHAR; i++) {

        int len;
        if (cc[i] > 0) {
            if ((len = cc[i] * MAX_STAR / max) == 0) {
                len = 1;
            }
        } else {
            len = 0;
        }

        // 只打印出现的字符
        if (len > 0) {
            printf("%c - %5d:", (char)i, cc[i]);
            while (len > 0) {
                putchar('*');
                len--;
            }
            putchar('\n');
        }

    }


}
