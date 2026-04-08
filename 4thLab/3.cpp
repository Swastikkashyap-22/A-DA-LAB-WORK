// Permutation Generator

#include <iostream>
#include <string>
#include <chrono>
using namespace std;

void swapChars(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void permute(string &str, int left, int right) {
    if (left == right) {
        cout << str << endl;
    } else {
        for (int i = left; i <= right; i++) {
            swapChars(str[left], str[i]);
            permute(str, left + 1, right);
            swapChars(str[left], str[i]);
        }
    }
}

int main() {
    string input = "abcd";
    int n = input.size();
    
    cout << "Permutations of " << input << ":" << endl;

    auto start = chrono::high_resolution_clock::now();
    permute(input, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();

    auto duration_ms = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration_ms.count() << " microseconds" << endl;

    return 0;
}