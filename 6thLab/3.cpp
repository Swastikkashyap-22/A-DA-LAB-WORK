// Prim's Algorithm

#include <iostream>
#include <climits>
#include <chrono> 

using namespace std;
using namespace std::chrono;

const int V = 8;
const int INF = INT_MAX;

void initGraph(int graph[V][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
}

void addEdge(int graph[V][V], int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
}

void printGraph(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
}

void primMST(int cost[V][V]) {
    int near[V];
    int mst[2][V - 1];

    int u = 0, v = 0;
    int minEdge = INF;

    for (int i = 0; i < V; i++) {
        for (int j = i; j < V; j++) {
            if (cost[i][j] != 0 && cost[i][j] < minEdge) {
                minEdge = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    mst[0][0] = u;
    mst[1][0] = v;
    int totalCost = cost[u][v];

    for (int i = 0; i < V; i++) {
        if (i == u || i == v) {
            near[i] = -1;
        } else {
            int cu = (cost[i][u] == 0) ? INF : cost[i][u];
            int cv = (cost[i][v] == 0) ? INF : cost[i][v];
            near[i] = (cu < cv) ? u : v;
        }
    }

    for (int i = 1; i < V - 1; i++) {
        int k = -1;
        int smallest = INF;

        for (int j = 0; j < V; j++) {
            if (near[j] != -1 && cost[j][near[j]] < smallest) {
                smallest = cost[j][near[j]];
                k = j;
            }
        }

        mst[0][i] = k;
        mst[1][i] = near[k];
        totalCost += cost[k][near[k]];

        near[k] = -1;

        for (int j = 0; j < V; j++) {
            if (near[j] != -1) {
                int ck = (cost[j][k] == 0) ? INF : cost[j][k];
                int cn = (cost[j][near[j]] == 0) ? INF : cost[j][near[j]];

                if (ck < cn) {
                    near[j] = k;
                }
            }
        }
    }

    cout << "\nMinimum Spanning Tree:\n";
    for (int i = 0; i < V - 1; i++) {
        cout << mst[0][i] << " - " << mst[1][i]
             << "  Cost: " << cost[mst[0][i]][mst[1][i]] << endl;
    }

    cout << "Total Cost = " << totalCost << endl;
}

int main() {
    int graph[V][V];

    initGraph(graph);

    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 5);
    addEdge(graph, 1, 4, 11);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 2, 5, 7);
    addEdge(graph, 3, 5, 2);
    addEdge(graph, 4, 5, 8);
    addEdge(graph, 4, 6, 9);
    addEdge(graph, 5, 6, 1);
    addEdge(graph, 5, 7, 10);
    addEdge(graph, 6, 7, 12);

    cout << "Adjacency Matrix:\n";
    printGraph(graph);

    auto start = high_resolution_clock::now();
    primMST(graph);
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(end - start);

    cout << "\nTime taken by Prim's Algorithm: " << duration.count() << " microseconds" << endl;

    return 0;
}