// main.cpp
// David Gurevich
// November 5, 2019
// CCC 10 J5

#include <bits/stdc++.h>

bool in_bounds(int x, int y) { return 0 <= x && x <= 7 && 0 <= y  && y <= 7; }

int main() {
    int chessboard[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            chessboard[i][j] = INT_MAX;
    }

    int A_x, A_y, B_x, B_y;
    std::cin >> A_x >> A_y >> B_x >> B_y;
    B_x--;
    B_y--;

    std::deque<std::pair<int, int>> Q;
    Q.push_back( {A_x - 1, A_y - 1} );
    chessboard[A_x - 1][A_y - 1] = 0;

    while (Q.size()) {
        int x = Q[0].first;
        int y = Q[0].second;
        Q.pop_front();

        // Work through neighbours
        if (in_bounds(x + 1, y + 2) && chessboard[x + 1][y + 2] > chessboard[x][y] + 1) {
            Q.push_back( std::make_pair(x + 1, y + 2) );
            chessboard[x + 1][y + 2] = chessboard[x][y] + 1;
        }

        if (in_bounds(x + 2, y + 1) && chessboard[x + 2][y + 1] > chessboard[x][y] + 1) {
            Q.push_back( std::make_pair(x + 2, y + 1) );
            chessboard[x + 2][y + 1] = chessboard[x][y] + 1;
        }
        
        if (in_bounds(x + 1, y - 2) && chessboard[x + 1][y - 2] > chessboard[x][y] + 1) {
            Q.push_back( std::make_pair(x + 1, y - 2) );
            chessboard[x + 1][y - 2] = chessboard[x][y] + 1;
        }

        if (in_bounds(x - 1, y - 2) && chessboard[x - 1][y - 2] > chessboard[x][y] + 1) {
            Q.push_back( std::make_pair(x - 1, y - 2) );
            chessboard[x - 1][y - 2] = chessboard[x][y] + 1;
        }

        if (in_bounds(x - 2, y - 1) && chessboard[x - 2][y - 1] > chessboard[x][y] + 1) {
            Q.push_back( std::make_pair(x - 2, y - 1) );
            chessboard[x - 2][y - 1] = chessboard[x][y] + 1;
        }

        if (in_bounds(x - 2, y + 1) && chessboard[x - 2][y + 1] > chessboard[x][y] + 1) {
            Q.push_back( std::make_pair(x - 2, y + 1) );
            chessboard[x - 2][y + 1] = chessboard[x][y] + 1;
        }
        
        if (in_bounds(x - 1, y + 2) && chessboard[x - 1][y + 2] > chessboard[x][y] + 1) {
            Q.push_back( std::make_pair(x - 1, y + 2) );
            chessboard[x - 1][y + 2] = chessboard[x][y] + 1;
        }
    }

    std::cout << chessboard[B_x][B_y] << std::endl;
    
    return 0;
}

