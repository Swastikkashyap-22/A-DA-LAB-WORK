// Iterative Quick Sort (Smaller partition solved first)

#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

void quickSort(int arr[], int n){
    if(n <= 1) return;

    int *lstack = new int[n];
    int *hstack = new int[n];
    int top = -1;

    int l = 0, h = n - 1;

    while(true){
        while(l < h){
            int i = l, j = h;
            int pivot = arr[(l + h) / 2];

            while(i <= j){
                while(arr[i] < pivot) i++;
                while(arr[j] > pivot) j--;
                if(i <= j){
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                    i++; 
                    j--;
                }
            }

            if(j - l < h - i){
                if(i < h){
                    lstack[++top] = i;
                    hstack[top] = h;
                }
                h = j;
            } else {
                if(l < j){
                    lstack[++top] = l;
                    hstack[top] = j;
                }
                l = i;
            }
        }

        if(top < 0) break;
        l = lstack[top];
        h = hstack[top--];
    }

    delete[] lstack;
    delete[] hstack;
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