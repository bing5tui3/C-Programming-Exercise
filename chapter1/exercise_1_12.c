#include <stdio.h>

#define IN  0
#define OUT 1

int main() {

    int c;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == ' ' || c == '\n') {
            if (state == IN) {
                state = OUT;
                putchar('\n');
            }
        }
        else {
            if (state == OUT) {
                state = IN;
            }
            putchar(c);
        }
    }

}