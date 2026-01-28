// Linear Search

// #include<iostream>
// using namespace std;

// void LSearch(int a[], int n, int element, int i) {
//     if (i == n) {
//         cout << "Element not found!" << endl;
//         return;
//     }
//     else if (a[i] == element) {
//         cout << "Element found!" << endl;
//         cout << "Index at which number is present: " << i + 1 << endl;
//         return;
//     }
//     else
//         LSearch(a, n, element, i + 1);
// }

// int main() {
//     int arr[5] = {4, 1, 5, 2, 3};
//     LSearch(arr, 5, 5, 0);
//     return 0;
// }


#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void LSearch(int a[], int n, int element, int i) {
    if (i == n) {
        cout << "Element not found!" << endl;
        return;
    }
    else if (a[i] == element) {
        cout << "Element found!" << endl;
        cout << "Index at which number is present: " << i + 1 << endl;
        return;
    }
    else
        LSearch(a, n, element, i + 1);
}

void print(int A[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> sizeDist(1, 100);
    int n = sizeDist(gen);

    int* arr = new int[n];

    uniform_int_distribution<> valueDist(1, 10000);
    for (int i = 0; i < n; i++) {
        arr[i] = valueDist(gen);
    }

    int element;
    cout << "Enter the element to be search: " << endl;
    cin >> element;

    auto start = high_resolution_clock::now();
    print(arr, n);
    LSearch(arr, n, element, 0);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << duration.count() << endl;

    delete[] arr;
    return 0;
}