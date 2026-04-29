// Travelling Sales Person

#include <iostream>
#include <climits>
using namespace std;

int *memo;
int n;

int travelRec(int adj[][20], int vertex, int completedVisit, int mask) {
    if (mask == completedVisit) {
        return adj[vertex][0];
    }

    int index = mask * n + vertex;

    if (memo[index] != INT_MAX) {
        return memo[index];
    }

    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            int newAns = adj[vertex][i] +
                         travelRec(adj, i, completedVisit, mask | (1 << i));

            if (newAns < memo[index]) {
                memo[index] = newAns;
            }
        }
    }

    return memo[index];
}

int solve(int adj[][20], int size) {
    n = size;
    int totalStates = (1 << n);

    memo = new int[totalStates * n];

    for (int i = 0; i < totalStates * n; i++) {
        memo[i] = INT_MAX;
    }

    int completedVisit = (1 << n) - 1;

    return travelRec(adj, 0, completedVisit, 1);
}

int main() {
    int adj[20][20] = {
        {0, 22, 26, 30},
        {30, 0, 45, 35},
        {25, 45, 0, 60},
        {30, 35, 40, 0}
    };

    int size = 4;

    int result = solve(adj, size);

    cout << "Minimum TSP cost: " << result << endl;

    delete[] memo;

    return 0;
}