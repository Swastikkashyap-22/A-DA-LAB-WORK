// Subset Sum

#include <iostream>
using namespace std;

#define LIMIT 10

void printSubset(int subset[], int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << subset[i] << " ";
    }
    cout << "}\n";
}

void generateSubsets(int arr[], int n, int target, int pos, int sum,
                     int temp[], int len, int &count) {

    if (sum == target) {
        count++;
        printSubset(temp, len);
    }

    if (pos == n || sum > target) {
        return;
    }

    temp[len] = arr[pos];
    generateSubsets(arr, n, target, pos + 1, sum + arr[pos], temp, len + 1, count);

    generateSubsets(arr, n, target, pos + 1, sum, temp, len, count);
}

int main() {
    int arr[LIMIT] = {1, 2, 3, 4, 5};
    int n = 5;
    int target = 7;

    int temp[LIMIT];
    int count = 0;

    cout << "Valid subsets:\n";
    generateSubsets(arr, n, target, 0, 0, temp, 0, count);

    cout << "\nTotal subsets with sum " << target << ": " << count << endl;

    return 0;
}