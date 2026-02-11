// Binary Search

#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

int binSearch(int arr[], int target, int start, int end){
    if(start > end) return -1;
    int mid = (end - start)/2 + start;
    if(arr[mid] == target) return mid;
    if(arr[mid] < target){
        return binSearch(arr, target, mid + 1, end);
    }else{
        return binSearch(arr, target, start, mid - 1);
    }
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
    int result = binSearch(arr, target, 0, n - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Target: " << target << endl;
    cout << "Index Found: " << result << endl;
    cout << "Time Taken: " << duration.count() << " microseconds" << endl;

    return 0;
}