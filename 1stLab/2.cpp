// Tower of Hanoi

#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

void TOH(int n, char F, char U, char T){
    if (n == 1)
        cout << "Move disc from " << F << " -> " << T << endl;
    else{
        TOH(n-1, F, T, U);
        cout << "Move disc from " << F << " -> " << T << endl;
        TOH (n-1, U, F, T);
    }
}

int main (){
    auto start = high_resolution_clock::now();
    TOH(3, 'A', 'B', 'C');
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " milliseconds";
    
    return 0;
}