// To find the number of bounces of the ball

#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;

int Tips(float v, int n){
    if (v <= 1){
        return n;
    }
    else {
        Tips((0.575)*v, n+1);
    }
}

int main(){
    float vel;
    int n = 0;

    cout << "Enter the initial velocity of ball: " << endl;
    auto start = high_resolution_clock::now();
    cin >> vel;
    auto stop = high_resolution_clock::now();

    cout << "Number of times the ball bounces = " << Tips(vel, n) << endl;
    
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " milliseconds";

    return 0;
}