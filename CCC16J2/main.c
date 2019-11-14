// main.c
// David Gurevich
// October 16, 2019
// ----------------
// CCC '16 J2

#include <stdio.h>
#include <stdbool.h>

bool allElementsEqual(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] != arr[0])
            return false;
    }
    return true;
}

int main() {
    int square[4][4] = {{ 0 }};
    int sums[8] = { 0 };
    int entry = 0;

    // Populate the square
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &entry);
            square[i][j] = entry;
        }
    }

    // Get sum of all rows
    int count = 0;
    for (int i = 0; i < 4; i++) {
        count = 0;
        for (int j = 0; j < 4; j++) {
            count += square[i][j];
        }
        sums[i] = count;
    }

    // Get sum of all cols
    for (int j = 0; j < 4; j++) {
        count = 0;
        for (int i = 0; i < 4; i++) {
            count += square[i][j];
        }
        sums[4 + j] = count;
    }

    if (allElementsEqual(sums, 8))
        printf("magic\n");
    else
        printf("not magic\n");

    return 0;
}

