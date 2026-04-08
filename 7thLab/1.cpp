// Finding stages in a multistage problem

#include<iostream>
#include<chrono>
#include<queue>
using namespace std;
using namespace std::chrono;

const int INF = 9999999;

int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[n][n];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                cost[i-1][j-1] = 0;
            else
                cost[i-1][j-1] = INF;
        } 
    }

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (source, destination, weight):\n";
    for(int i = 1; i <= e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u-1][v-1] = w;
    }
    
    cout << "\nCost Matrix:\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(cost[i-1][j-1] == INF)
                cout << "INF\t";
            else
                cout << cost[i-1][j-1] << "  \t";
        }
        cout << endl;
    }

    vector<int> stage[n];
    int vertex_stage[n];
    for(int i=0;i<n;i++) vertex_stage[i]=-1;

    queue<int> q;
    q.push(0);
    vertex_stage[0] = 0;

    auto start = high_resolution_clock::now();
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v=0; v<n; v++) {
            if(cost[u][v] != INF && vertex_stage[v]==-1) {
                vertex_stage[v] = vertex_stage[u]+1;
                q.push(v);
            }
        }
    }

    int max_stage = -1;
    for(int i=0;i<n;i++) {
        if(vertex_stage[i]>max_stage) max_stage = vertex_stage[i];
    }

    vector<int> stages[max_stage+1];
    for(int i=0;i<n;i++) {
        if(vertex_stage[i]!=-1)
            stages[vertex_stage[i]].push_back(i+1); 
    }
    auto end = high_resolution_clock::now();

    cout << "\nVertices per stage:\n";
    for(int i=0;i<=max_stage;i++) {
        cout << "Stage " << i+1 << ": ";
        for(int v : stages[i]) cout << v << " ";
        cout << endl;
    }

    auto duration = duration_cast<microseconds>(end - start); // Time taken for BFS and stage processing
    cout << "\nTime taken: " << duration.count() << " microseconds" << endl; 

    return 0;
}

/*
1 2 2
1 3 5
1 4 6
1 5 3
2 6 3
3 6 6
3 7 4
3 8 8
4 8 1
5 8 8
6 9 2
7 9 2
7 10 9
8 10 6
9 11 3
10 11 5
*/