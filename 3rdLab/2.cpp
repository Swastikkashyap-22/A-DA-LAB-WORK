// Merge Sort

#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int left, int mid, int right, int temp[]) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int x = left; x <= right; x++)
        arr[x] = temp[x];
}

void mergeSort(int arr[], int n) {
    int* temp = new int[n];

    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int endIdx = left + 2 * size - 1;
            int right = (endIdx < n - 1) ? endIdx : (n - 1);
            merge(arr, left, mid, right, temp);
        }
    }
    delete[] temp;
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
    mergeSort(arr, n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    print(arr, n);
    cout << endl;
    cout << "Time taken: " << duration.count() << " microseconds";

    delete[] arr;

    return 0;
}