// NQueens Problem

#include <iostream>
#include <cmath>
using namespace std;

bool place(int queenNum, int pos[], int n) {
    if (queenNum == n) return true;

    for (int i = 0; i < n; i++) {
        bool conflict = false;

        for (int j = 0; j < queenNum; j++) {
            int queenY = pos[j];
            if (abs(queenNum - j) == abs(i - queenY) || queenY == i) {
                conflict = true;
                break;
            }
        }

        if (conflict) continue;

        pos[queenNum] = i;

        if (place(queenNum + 1, pos, n)) return true;
    }

    return false;
}

void solve(int n, int pos[]) {
    place(0, pos, n);
}

int main() {
    int n = 4;
    int pos[100];

    solve(n, pos);

    cout << "Queen positions (1-based index): ";
    for (int i = 0; i < n; i++) {
        cout << (pos[i] + 1) << " ";
    }
    cout << endl;

    return 0;
}