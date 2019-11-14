/*
    CCC '02 S2 - Fraction Action
    ============================
    main.c
    David Gurevich
    May 12, 2019
*/

#include <stdio.h>

int main() {
    int num = 0;
    int denom = 0;

    // get numerator and denominator
    scanf("%d", &num);
    scanf("%d", &denom);

    // Get whole part of mixed fraction
    int whole = num / denom;
    num -= (whole * denom);

    // Get GCD and fully reduce num and denom
    int a = num;
    int b = denom;
    int c = a % b;
    while (c > 0) {
        a = b;
        b = c;
        c = a % b;
    }

    int gcd = b;

    num /= gcd;
    denom /= gcd;

    // Print properly

    // If whole is zero, but num is not
    if (whole == 0 && num != 0)
        printf("%d/%d\n", num, denom);
    // If num is zero
    if (num == 0)
        printf("%d\n", whole);
    // If whole and num are not zero
    if (whole != 0 && num != 0) {
        printf("%d %d/%d\n", whole, num, denom);
    }

    return 0;
}
