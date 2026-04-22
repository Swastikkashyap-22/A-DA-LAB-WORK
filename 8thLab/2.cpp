// MSG Shortest Path
#include <iostream>
#include <climits>
using namespace std;

int *cost, *d, *p;

int solveRecFwd(int **adjMatrix, int currentVertex, int len) {
    if (cost[currentVertex] != INT_MAX) return cost[currentVertex];

    for (int i = currentVertex + 1; i < len; i++) {
        if (adjMatrix[currentVertex][i] != 0) {
            int nextStageDist = solveRecFwd(adjMatrix, i, len);
            if (nextStageDist + adjMatrix[currentVertex][i] < cost[currentVertex]) {
                cost[currentVertex] = nextStageDist + adjMatrix[currentVertex][i];
                d[currentVertex] = i;
            }
        }
    }
    return cost[currentVertex];
}

int solveRecBwd(int **adjMatrix, int currentVertex, int len) {
    for (int i = currentVertex + 1; i < len; i++) {
        if (adjMatrix[currentVertex][i] != 0) {
            int currNxtStgDist = adjMatrix[currentVertex][i] + cost[i];
            if (currNxtStgDist < cost[currentVertex]) {
                cost[currentVertex] = currNxtStgDist;
                d[currentVertex] = i;
            }
        }
    }
    if (currentVertex != 0) return solveRecBwd(adjMatrix, currentVertex - 1, len);
    return cost[0];
}

int traverse(int **adjMatrix, int source, int stage, int n) {
    for (int i = 0; i < n; i++) {
        if (adjMatrix[source][i] > 0) {
            stage = traverse(adjMatrix, i, stage, n);
            break;
        }
    }
    return stage + 1;
}

void printPath(int stageChoice[], int numOfStages, int n) {
    p = new int[numOfStages];
    p[0] = 0;
    p[numOfStages - 1] = n - 1;

    for (int i = 1; i < numOfStages - 1; i++) {
        p[i] = d[p[i - 1]];
    }

    for (int i = 0; i < numOfStages; i++) {
        cout << p[i] << " --> ";
    }
    cout << endl;

    delete[] p;
}

int algorithmFWD(int **adjMatrix, int n) {
    cost = new int[n];
    d = new int[n];

    for (int i = 0; i < n; i++) cost[i] = INT_MAX;
    cost[n - 1] = 0;

    int shortestPath = solveRecFwd(adjMatrix, 0, n);
    int numOfStages = traverse(adjMatrix, 0, 0, n);
    printPath(d, numOfStages, n);

    delete[] cost;
    delete[] d;

    return shortestPath;
}

int algorithmBWD(int **adjMatrix, int n) {
    cost = new int[n];
    d = new int[n];

    for (int i = 0; i < n; i++) cost[i] = INT_MAX;
    cost[n - 1] = 0;

    int shortestPath = solveRecBwd(adjMatrix, n - 2, n);
    int numOfStages = traverse(adjMatrix, 0, 0, n);
    printPath(d, numOfStages, n);

    delete[] cost;
    delete[] d;

    return shortestPath;
}

int main() {
    int n = 8;

    int temp[8][8] = {
        {0, 5, 2, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 7, 3, 0, 0},
        {0, 0, 0, 0, 4, 6, 0, 0},
        {0, 0, 0, 0, 5, 2, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    int **adjMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = temp[i][j];
        }
    }

    int result = algorithmFWD(adjMatrix, n);
    cout << "Shortest Path is: " << result << endl;

    for (int i = 0; i < n; i++) delete[] adjMatrix[i];
    delete[] adjMatrix;

    return 0;
}