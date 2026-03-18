// Dijkestra (Single source shortest path)

#include <iostream>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

const int INF = 999999;

void Dijkstra(int cost[][10], int n, int v, int visited[], int dist[]) {

    for(int i = 1; i <= n; i++){
        visited[i] = 0;
        dist[i] = cost[v][i];
    }

    visited[v] = 1;
    dist[v] = 0;

    for(int j = 2; j <= n-1; j++){

        int min = INF;
        int u = -1;

        for(int i = 1; i <= n; i++){
            if(visited[i] == 0 && dist[i] < min){
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        for(int w = 1; w <= n; w++){
            if(visited[w] == 0 && cost[u][w] != INF){
                if(dist[w] > dist[u] + cost[u][w]){
                    dist[w] = dist[u] + cost[u][w];
                }
            }
        }
    }
}

void displayMatrix(int cost[][10], int n) {
    cout << "Cost Matrix:\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cost[i][j] == INF)
                cout << "INF\t";
            else
                cout << cost[i][j] << "  \t";
        }
        cout << endl;
    }
}

void displayDistance(int dist[], int n, int v) {
    cout << "\nShortest distances from source vertex " << v << ":\n";
    for(int i = 1; i <= n; i++){
        cout << " " << v << " -> " << i << " = " << dist[i] << endl;
    }
}

int main() {

    int cost[10][10];
    int visited[10];
    int dist[10];

    random_device rd;
    mt19937 gen(rd() + steady_clock::now().time_since_epoch().count());

    uniform_int_distribution<> nodeDist(5, 10);
    int n = nodeDist(gen);
    cout << "The number of Vertices: " << n << endl;

    uniform_int_distribution<> sourceDist(1, n);
    int source = sourceDist(gen);
    cout << "The Source Vertex is: " << source << endl;

    uniform_int_distribution<> weight(1, 200);
    uniform_int_distribution<> edge(0, 1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                cost[i][j] = 0;
            else{
                if(edge(gen))
                    cost[i][j] = weight(gen);
                else
                    cost[i][j] = INF;
            }
        }
    }

    displayMatrix(cost, n);

    auto start = high_resolution_clock::now();

    Dijkstra(cost, n, source, visited, dist);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    displayDistance(dist, n, source);

    cout << "\nTime taken: " << duration.count() << " nanoseconds\n";

    return 0;
}