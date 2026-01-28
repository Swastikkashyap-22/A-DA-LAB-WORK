// Bubble Sort

#include<iostream>
using namespace std;

void bubSort(int A[], int n){

    for(int i = 0 ; i < n-1 ; i++){
        bool isSwap = false;
        
        for(int j = 0; j < n-1-i ; j++){
            if(A[j] > A[j+1]){
                swap(A[j], A[j+1]);
                isSwap = true;
            }
        }

        if(!isSwap){
            return;
        }
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

    bubSort(arr, 5);
    print(arr, 5);

    return 0;
}