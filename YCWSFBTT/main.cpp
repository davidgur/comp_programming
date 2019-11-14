// main.cpp
// David Gurevich
// November 13, 2019
// You Can't Write Science Fiction Better Than This

#include <iostream>
#include <vector>
#include <deque>
#include <climits>

int shortest_distance(int A, int B);

std::vector<std::vector<int>> locs;

int main() {
    int N, M, A, B;
    std::cin >> N >> M >> A >> B;

    locs.resize(N + 1);

    int x, y;
    for (int i = 0; i < M; i++) {
        std::cin >> x >> y;
        locs[x].push_back(y);
        locs[y].push_back(x);
    }

    int total_distance = shortest_distance(1, A) + shortest_distance(A, B);

    if (total_distance < 0)
        std::cout << -1 << std::endl;
    else
        std::cout << total_distance << std::endl;

    return 0;
}

int shortest_distance(int A, int B) {
    std::deque<int> Q;
    Q.push_back(A);

    std::vector<int> distances(locs.size(), INT_MAX);
    distances[A] = 0;

    while (Q.size()) {
        int node = Q[0];
        Q.pop_front();

        for (int& neighbour : locs[node]) {
            if (distances[neighbour] > distances[node] + 1) {
                distances[neighbour] = distances[node] + 1;
                Q.push_back(neighbour);
            }
        }
    }

    return distances[B];
 }

