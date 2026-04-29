// Floyd Warshall (Pair Shortest Path)

#include <iostream>
#include <climits>
#include <chrono>
using namespace std;
using namespace chrono;

class PairShortestPath {
private:
    string name;

public:
    PairShortestPath(string name) {
        this->name = name;
    }

    void solve(int n, int adjacency_matrix[][100], int result[][100]) {
        int current_distance[100][100];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    current_distance[i][j] = 0;
                } else if (adjacency_matrix[i][j] == 0) {
                    current_distance[i][j] = INT_MAX / 200;
                } else {
                    current_distance[i][j] = adjacency_matrix[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (current_distance[j][i] + current_distance[i][k] < current_distance[j][k]) {
                        current_distance[j][k] = current_distance[j][i] + current_distance[i][k];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = current_distance[i][j];
            }
        }
    }
};

int main() {
    int n = 4;

    int adjacency_matrix[100][100] = {
        {0, 3, 0, 7},
        {8, 0, 2, 0},
        {5, 0, 0, 1},
        {2, 0, 0, 0}
    };

    int result[100][100];

    PairShortestPath psp("PairShortestPath");

    auto start = high_resolution_clock::now();

    psp.solve(n, adjacency_matrix, result);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Shortest path matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (result[i][j] >= INT_MAX / 200)
                cout << "INF ";
            else
                cout << result[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;

    return 0;
}