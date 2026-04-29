// Matrix Chain Multiplication

#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int dimMatrix[], int n) {
    int len = n - 1;

    int memo[20][20];
    int s[20][20];

    for (int i = 0; i < len; i++) {
        memo[i][i] = 0;
    }

    for (int l = 2; l <= len; l++) {
        for (int i = 0; i < len - l + 1; i++) {
            int j = i + l - 1;
            memo[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int q = memo[i][k] + memo[k + 1][j] +
                        dimMatrix[i] * dimMatrix[k + 1] * dimMatrix[j + 1];

                if (q < memo[i][j]) {
                    memo[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    return memo[0][len - 1];
}

int main() {
    int dimMatrix[] = {6, 3, 7, 2, 5, 4};
    int n = sizeof(dimMatrix) / sizeof(dimMatrix[0]);

    int result = matrixChainMultiplication(dimMatrix, n);

    cout << "Minimum multiplication cost: " << result << endl;

    return 0;
}