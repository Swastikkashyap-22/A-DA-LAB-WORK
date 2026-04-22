// Matrix Chain Multiplication
#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int dimMatrix[], int n) {
    int len = n - 1;

    int** memo = new int*[len];
    int** s = new int*[len];
    for (int i = 0; i < len; i++) {
        memo[i] = new int[len];
        s[i] = new int[len];
    }

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

    int result = memo[0][len - 1];

    for (int i = 0; i < len; i++) {
        delete[] memo[i];
        delete[] s[i];
    }
    delete[] memo;
    delete[] s;

    return result;
}

int* input(int &n) {
    cout << "Enter number of dimensions: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter dimension " << (i + 1) << ": ";
        cin >> arr[i];
    }
    return arr;
}

int main() {
    int dimMatrix[] = {5, 4, 6, 2, 7};
    int n = sizeof(dimMatrix) / sizeof(dimMatrix[0]);

    int result = matrixChainMultiplication(dimMatrix, n);
    cout << result << endl;

    return 0;
}