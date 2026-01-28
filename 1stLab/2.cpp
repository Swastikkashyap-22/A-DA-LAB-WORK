// Tower of Hanoi

#include<iostream>
using namespace std;

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
    TOH(3, 'A', 'B', 'C');
    return 0;
}