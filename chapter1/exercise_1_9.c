#include "stdio.h"

#define IN  0
#define OUT 1


int main() {
    int c;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' && state == OUT) {
            state = IN;
        }
        else if (c != ' ') {
            if (state == IN) {
                putchar(' ');
                state = OUT;
            }
            putchar(c);
        }
    }
}
