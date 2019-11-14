#include <stdio.h>
#include <stdbool.h>

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    int K;                  // Number of cages
    scanf("%d", &K);

    bool cats[25][25] = { false }; // True or False | is there a cage?
    int cages[25][25] = { 0 };

    for (int i = 0; i < K; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        cats[x - 1][y - 1] = true;
    }

    for (int i = 0; i < R; i++) {
        if (!cats[i][0]) 
            cages[i][0] = 1;
        else
            break;
    }

    for (int j = 0; j < C; j++) {
        if (!cats[0][j])
            cages[0][j] = 1;
        else
            break;
    }

    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            if (!cats[i][j])
                cages[i][j] = cages[i - 1][j] + cages[i][j - 1];
        }
    }
        
    printf("%d\n", cages[R - 1][C - 1]);
    return 0;
}

