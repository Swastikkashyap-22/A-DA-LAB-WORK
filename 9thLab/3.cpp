// LCS (Longest Common Sequence)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int* memo;
int cols;

int solve(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();

    cols = m + 1;
    memo = new int[(n + 1) * (m + 1)];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            memo[i * cols + j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                memo[i * cols + j] = 1 + memo[(i - 1) * cols + (j - 1)];
            } else {
                memo[i * cols + j] = max(memo[(i - 1) * cols + j],
                                         memo[i * cols + (j - 1)]);
            }
        }
    }

    return memo[n * cols + m];
}

string getLCS(string text1, string text2) {
    int i = text1.length();
    int j = text2.length();
    string lcs = "";

    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs += text1[i - 1];
            i--;
            j--;
        }
        else if (memo[(i - 1) * cols + j] > memo[i * cols + (j - 1)]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int algorithm(string seq1, string seq2) {
    int result = solve(seq1, seq2);
    cout << getLCS(seq1, seq2) << endl;
    return result;
}

int main() {
    string seq1 = "Controller";
    string seq2 = "control";

    cout << algorithm(seq1, seq2) << endl;

    delete[] memo;

    return 0;
}