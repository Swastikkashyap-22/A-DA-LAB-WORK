// Consecutive Number

// Missing Number in Consecutive Series (XOR Method)

#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int findMissing(int lowerLimit, int upperLimit, int consec[], int size){
    int ans = 0;

    for(int i = 0; i < size; i++){
        ans = ans ^ consec[i];
    }

    for(int i = lowerLimit; i <= upperLimit; i++){
        ans = ans ^ i;
    }

    return ans;
}

int main(){
    int consec[] = {1,2,3,4,5,6,7,9};
    int size = sizeof(consec)/sizeof(consec[0]);

    auto start = high_resolution_clock::now();
    cout << findMissing(1, 9, consec, size) << endl;
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " milliseconds";

    return 0;
}
