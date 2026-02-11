// Bubble Sort

#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

void bubSort(int A[], int n){
    if(n == 1){
        return;
    } else {
        for(int j = 0; j < n-1; j++){
            if(A[j] > A[j+1]){
                swap(A[j], A[j+1]);
            }
        }
        bubSort(A, n-1);
    }
}

void print(int A[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    random_device rd;
    mt19937 gen(rd() + steady_clock::now().time_since_epoch().count());
    
    int n = 1000;

    int* arr = new int[n];

    uniform_int_distribution<> valueDist(1, 10000);
    for (int i = 0; i < n; i++) {
        arr[i] = valueDist(gen);
    }

    auto start = chrono::high_resolution_clock::now();
    bubSort(arr, n);
    auto end = chrono::high_resolution_clock::now();

    print(arr, n);

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    delete[] arr;
    
    return 0;
}