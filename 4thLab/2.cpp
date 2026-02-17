// Binary Sort (list divided into n/3 and 2n/3)

#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

int binSearch(int arr[], int n, int target){
    int low = 0, high = n - 1;

    while(low <= high){
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if(arr[mid1] == target) return mid1;
        if(arr[mid2] == target) return mid2;

        if(target < arr[mid1])
            high = mid1 - 1;
        else if(target > arr[mid2])
            low = mid2 + 1;
        else{
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
}

int main(){
    random_device rd;
    mt19937 gen(rd() + steady_clock::now().time_since_epoch().count());

    int n = 10000;
    int* arr = new int[n];

    uniform_int_distribution<> stepDist(1, 10);
    int currentVal = 0;
    for(int i = 0; i < n; i++){
        currentVal += stepDist(gen);
        arr[i] = currentVal;
    }

    uniform_int_distribution<> indexDist(0, n - 1);
    int randomIndex = indexDist(gen);
    int target = arr[randomIndex];

    auto start = high_resolution_clock::now();
    int result = binSearch(arr, n, target);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Target: " << target << endl;
    cout << "Index Found: " << result << endl;
    cout << "Time Taken: " << duration.count() << " microseconds" << endl;

    return 0;
}