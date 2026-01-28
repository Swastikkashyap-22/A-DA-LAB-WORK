// Aim: To find the value of x raised to power n

#include<iostream>
using namespace std;

// WITHOUT RECURSION
int Power(int x, int n){
    int m = n; int z = x; int Pow = 1;
    while(m>0){
        while(m%2 == 0){
            m = m/2;
            z = z*z;
        }
    m = m-1; 
    Pow = Pow*z;
    }
return Pow;
}

int main(){
    int x,n;
    cout << "Enter the values of x, n: " << endl;
    cin >> x;
    cin >> n;

    cout << "Value of " << x << " raised to power " << n << " = " << Power(x,n);
    return 0;
}

// WITH RECURSION
// int Power(int x, int n){
//     if (n == 0) return 1;
//     else if (n == 1) return x;
//     else {
//         int temp = Power(x, n/2);
//         if (n%2 == 0) 
//             return temp*temp;
//         else 
//             return temp*temp*x;
//     }
// }

// int main(){
//     int x,n;
//     cout << "Enter the values of x, n: " << endl;
//     cin >> x;
//     cin >> n;

//     cout << "Value of " << x << " raised to power " << n << " = " << Power(x,n);
//     return 0;
// }