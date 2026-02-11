// Iterative Quick Sort (Smaller partition solved first)

#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

void quickSort(int arr[], int n){

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
    for(int i = 0 ; i < n ; i++){
        arr[i] = valueDist(gen);
    }

    auto start = high_resolution_clock::now();
    quickSort(arr, n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    print(arr, n);
    cout << endl;
    cout << "Time taken: " << duration.count() << " microseconds";

    delete[] arr;

    return 0;
}