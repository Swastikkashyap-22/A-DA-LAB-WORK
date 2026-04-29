// Graph Coloring

#include <iostream>
using namespace std;

#define MAX 10

int n, m;
int G[MAX][MAX];
int col[MAX];

bool valid(int node, int c) {
    for (int i = 0; i < n; i++) {
        if (G[node][i] == 1 && col[i] == c) {
            return false;
        }
    }
    return true;
}

bool assignColor(int node) {
    if (node == n) return true;

    int c = 1;
    while (c <= m) {
        if (valid(node, c)) {
            col[node] = c;

            if (assignColor(node + 1)) return true;

            col[node] = 0;
        }
        c++;
    }
    return false;
}

int main() {
    n = 4;

    int input[MAX][MAX] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G[i][j] = input[i][j];
        }
    }

    m = 1;

    while (true) {
        for (int i = 0; i < n; i++) col[i] = 0;

        if (assignColor(0)) {
            cout << "Minimum colors needed: " << m << "\n\n";

            for (int i = 0; i < n; i++) {
                cout << "Vertex " << i << " -> Color " << col[i] << "\n";
            }
            break;
        }

        m++;
    }

    return 0;
}