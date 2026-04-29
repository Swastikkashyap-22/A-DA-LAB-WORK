// Hamiltonian Cycle

#include <iostream>
using namespace std;

#define LIMIT 10

int n;
int adj[LIMIT][LIMIT];
int cycle[LIMIT + 1];

bool canPlace(int node, int step) {
    if (adj[cycle[step - 1]][node] == 0)
        return false;

    for (int i = 0; i < step; i++) {
        if (cycle[i] == node)
            return false;
    }

    return true;
}

bool buildCycle(int step) {
    if (step == n) {
        if (adj[cycle[step - 1]][cycle[0]] == 1) {
            cycle[step] = cycle[0];
            return true;
        }
        return false;
    }

    int candidate = 1;
    while (candidate < n) {
        if (canPlace(candidate, step)) {
            cycle[step] = candidate;

            if (buildCycle(step + 1))
                return true;

            cycle[step] = -1;
        }
        candidate++;
    }

    return false;
}

int main() {
    n = 5;

    int input[LIMIT][LIMIT] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = input[i][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        cycle[i] = -1;
    }

    cycle[0] = 0;

    if (buildCycle(1)) {
        cout << "Hamiltonian Cycle:\n";
        for (int i = 0; i <= n; i++) {
            cout << cycle[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No cycle exists\n";
    }

    return 0;
}