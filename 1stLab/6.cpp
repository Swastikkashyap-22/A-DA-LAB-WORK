// Earliest Duplticate 

#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int earliestDuplicate(int arr[], int size){
    int uppermid = (size + 1)/2;
    for(int i = uppermid - 1 ; i >= 0; i--){
        for(int j = i - 1 ; j >= 0 ; j--){
            if(arr[i] == arr[j]) uppermid = i;
        }
    }
    return uppermid;
}

int main(){
    int arr[] = {1, 2, 5, 1, 4, 4, 3, 2, 3, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    auto start = high_resolution_clock::now();
    cout << earliestDuplicate(arr, size) << endl;
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " milliseconds";

    return 0;
}
