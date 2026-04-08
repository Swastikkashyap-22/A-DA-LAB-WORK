// kth Smallest

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int divide(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (true) {
        while (i <= right && arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i >= j) break;

        swap(arr[i], arr[j]);
    }

    swap(arr[left], arr[j]);
    return j;
}

int kthSmallest(int arr[], int left, int right, int k) {
    int pos = divide(arr, left, right);

    if (pos == k - 1) return arr[pos];
    else if (pos > k - 1) return kthSmallest(arr, left, pos - 1, k);
    else return kthSmallest(arr, pos + 1, right, k);
}

int main() {
    int numbers[8] = {12, 3, 8, 19, 7, 21, 4, 15};
    int k = 4;

    auto start = high_resolution_clock::now();

    int result = kthSmallest(numbers, 0, 7, k);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "The " << k << "-th smallest element is " << result << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}