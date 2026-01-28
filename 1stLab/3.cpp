// To find the number of bounces of the ball

#include<iostream>
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
    cin >> vel;

    cout << "Number of times the ball bounces = " << Tips(vel, n);

    return 0;
}