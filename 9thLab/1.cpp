#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

int knapsack(int W, int wt[], int val[], int n) {
    int v[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            }
            else if (wt[i - 1] <= j) {
                v[i][j] = max(val[i - 1] + v[i - 1][j - wt[i - 1]], v[i - 1][j]);
            }
            else {
                v[i][j] = v[i - 1][j];
            }
        }
    }

    return v[n][W];
}

int main() {
    int val[] = {20, 30, 40, 50};
    int wt[] = {1, 3, 4, 6};
    int W = 10;
    int n = sizeof(val) / sizeof(val[0]);

    auto start = high_resolution_clock::now();

    int result = knapsack(W, wt, val, n);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Maximum value: " << result << endl;
    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;

    return 0;
}