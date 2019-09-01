#include "stdio.h"

double fahr_to_calsius(double fahr);

int main() {
    double fahr, celsius;
    double lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("fahr to celsius transfer table:\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = fahr_to_calsius(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

double fahr_to_calsius(double fahr) {
    return 5.0 * (fahr - 32.0) / 9.0;
}