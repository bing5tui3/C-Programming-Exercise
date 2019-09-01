#include "stdio.h"

#define MAX_STAR   10  /* 最大值打印的星星数 */
#define MAX_LENGTH 10  /* 单词最大长度，超过该长度的统一归类为其他*/
#define IN  0
#define OUT 1

int main() {

    int c;
    int lc[MAX_LENGTH + 1];   /* length count */
    int wl;                    /* word length */
    int state;

    wl = 0;
    state = OUT;
    for (int i = 0; i < MAX_LENGTH + 1; i++) {
        lc[i] = 0;
    }

    // 统计单词长度，和各个长度下出现的数量
    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == ' ' || c == '\n') {
            if (state == IN) {
                state = OUT;
                if (wl > MAX_LENGTH) {
                    lc[MAX_LENGTH]++;
                } else {
                    lc[wl]++;
                }
            }
        }
        else {
           if (state == OUT) {
               state = IN;
               wl = 0;
           }
           wl++;
        }
    }

    // 找出最大长度
    int maxLen = 0;
    for (int i = 0; i < MAX_LENGTH + 1; i++) {
        int len = lc[i];
        if (len > maxLen) {
            maxLen = len;
        }
    }

    // 打印水平的直方图
    int len;
    for (int i = 0; i < MAX_LENGTH + 1; i++) {
        if (i < MAX_LENGTH) {
            printf("%5d - %5d:", i, lc[i]);
        } else {
            printf("other - %5d:", lc[i]);
        }

        if (lc[i] > 0) {
            // 打印的星星数量根据比例折算，最大值按MAX_STAR个数打印
            if ((len = lc[i] * MAX_STAR / maxLen) == 0) {
                len = 1;
            }
        } else {
            len = 0;
        }

        while (len > 0) {
            putchar('*');
            len--;
        }

        putchar('\n');
    }

}