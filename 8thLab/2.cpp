#include <iostream>
#include <climits>
#include <chrono>
using namespace std;
using namespace chrono;

#define INF 999999

int graph[20][20];
int cost[20];
int nextNode[20];
int n = 7;

int computePath(int u) {
    if (u == n - 1) return 0;

    if (cost[u] != -1) return cost[u];

    cost[u] = INF;

    for (int v = u + 1; v < n; v++) {
        if (graph[u][v] != 0) {
            int temp = graph[u][v] + computePath(v);

            if (temp < cost[u]) {
                cost[u] = temp;
                nextNode[u] = v;
            }
        }
    }

    return cost[u];
}

void printPath() {
    int node = 0;

    cout << "Path: ";
    while (node != n - 1) {
        cout << node << " -> ";
        node = nextNode[node];
    }
    cout << node << endl;
}

int main() {

    int temp[7][7] = {
        {0, 3, 6, 2, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 0},
        {0, 0, 0, 0, 2, 3, 0},
        {0, 0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = temp[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cost[i] = -1;
        nextNode[i] = -1;
    }

    auto start = high_resolution_clock::now();

    int result = computePath(0);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);

    cout << "Minimum Cost: " << result << endl;

    printPath();

    cout << "Execution Time: " << duration.count() << " ns" << endl;

    return 0;
}