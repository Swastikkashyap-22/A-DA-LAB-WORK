// Min Max

#include <iostream>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

void maxmin(int low, int high, int* arr, int &max, int &min)
{
    if(low == high){
        max = min = arr[low];
    }
    else if(low == high - 1){
        if(arr[low] < arr[high]){
            min = arr[low];
            max = arr[high];
        }
        else{
            min = arr[high];
            max = arr[low];
        }
    }
    else{
        int mid = (low + high) / 2;
        int max1, min1;

        maxmin(low, mid, arr, max, min);
        maxmin(mid + 1, high, arr, max1, min1);

        if(max < max1) max = max1;
        if(min > min1) min = min1;
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

    int n = 100;
    int* arr = new int[n];

    uniform_int_distribution<> valueDist(1, 10000);
    for(int i = 0 ; i < n ; i++){
        arr[i] = valueDist(gen);
    }
    
    int max, min;

    auto start = high_resolution_clock::now();
    maxmin(0, n - 1, arr, max, min);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    print(arr, n);

    cout << "Maximum = " << max << endl;
    cout << "Minimum = " << min << endl;

    cout << "Time taken: " << duration.count() << " nanoseconds";

    delete[] arr;

    return 0;
}
