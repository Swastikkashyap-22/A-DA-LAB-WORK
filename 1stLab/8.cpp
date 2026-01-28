// Selection Sort

#include<iostream>
using namespace std;

void selSort(int A[], int n){

    for(int i = 0 ; i < n-1 ; i++){
        int sIndex = i;

        for(int j = i+1 ; j < n ; j++){
            if(A[j] < A[sIndex]){
                sIndex = j;
            }
        }
        swap(A[i], A[sIndex]);
    }
}

void print(int A[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[5] = {4,1,5,2,3};

    selSort(arr, 5);
    print(arr, 5);

    return 0;
}