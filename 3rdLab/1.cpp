// Quick Sort

#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int i = start + 1;
    int j = end;
    while(i <= j){
        while(i <= end && arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[start], arr[j]);
    return j;
}

void quickSort(int arr[], int start, int end){
    if(start >= end) return;
    int pivotIdx = partition(arr, start, end);
    quickSort(arr, start, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, end);
}

void print(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    random_device rd;
    mt19937 gen(rd() + steady_clock::now().time_since_epoch().count());

    int n = 5000;
    int* arr = new int[n];

    uniform_int_distribution<> valueDist(1, 10000);
    for (int i = 0; i < n; i++) {
        arr[i] = valueDist(gen);
    }

    auto start = high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    print(arr, n);
    cout << endl;
    cout << "Time taken: " << duration.count() << " microseconds";

    delete[] arr;

    return 0;
}