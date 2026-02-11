// Horner's Law

#include<iostream>
#include<chrono>
#include<random>
using namespace std;
using namespace std::chrono;

int solveHorner(int arr[], int idx, int m, int x){
    if(idx == m + 1) return 0;
    return arr[idx] + x * solveHorner(arr, idx + 1, m, x);
}

int main(){
    random_device rd;
    mt19937 gen(rd() + steady_clock::now().time_since_epoch().count());

    int n = 10;
    int* arr = new int[n];
    
    uniform_int_distribution<> valueDist(1, 100);
    for (int i = 0; i < n; i++){
        arr[i] = valueDist(gen);
    }

    auto start = high_resolution_clock::now();
    cout << solveHorner(arr, 0, n - 1, 2) << endl;
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " milliseconds";

    delete[] arr;
    return 0;
}
