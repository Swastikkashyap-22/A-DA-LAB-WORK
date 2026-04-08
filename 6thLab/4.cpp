// Cycle Detection

#include <iostream>
#include <list>
using namespace std;

bool detectCycleUtil(int current, int prev, bool visited[], list<int> graph[]) {
    visited[current] = true;

    for (int adjNode : graph[current]) {
        if (!visited[adjNode]) {
            if (detectCycleUtil(adjNode, current, visited, graph)) {
                return true;
            }
        } 
        else if (adjNode != prev) {
            return true;
        }
    }
    return false;
}

bool checkCycle(int vertices, list<int> graph[]) {
    bool visited[vertices];

    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (detectCycleUtil(i, -1, visited, graph)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n = 4;

    cout << "--- First Graph ---" << endl;
    list<int> g1[n];

    g1[0].push_back(1);
    g1[0].push_back(2);
    g1[1].push_back(0);
    g1[1].push_back(2);
    g1[2].push_back(0);
    g1[2].push_back(1);
    g1[2].push_back(3);
    g1[3].push_back(2);

    if (checkCycle(n, g1)) {
        cout << "Cycle detected in first graph.\n\n";
    } else {
        cout << "No cycle in first graph.\n\n";
    }

    cout << "--- Second Graph ---" << endl;
    list<int> g2[n];

    g2[0].push_back(1);
    g2[1].push_back(0);
    g2[1].push_back(2);
    g2[2].push_back(1);
    g2[2].push_back(3);
    g2[3].push_back(2);

    if (checkCycle(n, g2)) {
        cout << "Cycle detected in second graph.\n";
    } else {
        cout << "No cycle in second graph.\n";
    }

    return 0;
}