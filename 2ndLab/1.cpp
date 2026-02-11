// Insertion Sort

#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n){

    for(int i = 1 ; i < n ; i++){
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
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
    insertionSort(arr, n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    print(arr, n);
    cout << endl;
    cout << "Time taken: " << duration.count() << " microseconds";

    delete[] arr;
    
    return 0;
}
