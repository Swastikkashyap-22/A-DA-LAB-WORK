// Selection Sort

#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

void selSort(int A[], int n, int i) {
    if (i == n - 1)
        return;

    int sIndex = i;
    for (int j = i + 1; j < n; j++) {
        if (A[j] < A[sIndex])
            sIndex = j;
    }
    swap(A[i], A[sIndex]);
    selSort(A, n, i + 1);
}

void print(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
        cout << endl;
}

int main() {
    random_device rd;
    mt19937 gen(rd() + steady_clock::now().time_since_epoch().count());

    int n = 1000;
    int* arr = new int[n];

    uniform_int_distribution<> valueDist(1, 10000);
    for (int i = 0; i < n; i++) {
        arr[i] = valueDist(gen);
    }

    auto start = chrono::high_resolution_clock::now();
    selSort(arr, n, 0);
    auto end = chrono::high_resolution_clock::now();

    print(arr, n);

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}