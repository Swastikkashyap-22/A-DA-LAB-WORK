// Knapsack Problem
 
#include <iostream>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

void copyMatrix(double a[][3], double b[][3], int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            b[i][j]=a[i][j];
}

void sortMinWeight(double a[][3], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j][0] > a[j+1][0])
                for(int k=0;k<3;k++)
                    swap(a[j][k], a[j+1][k]);
}

void sortMaxProfit(double a[][3], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j][1] < a[j+1][1])
                for(int k=0;k<3;k++)
                    swap(a[j][k], a[j+1][k]);
}

void sortMaxRatio(double a[][3], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j][2] < a[j+1][2])
                for(int k=0;k<3;k++)
                    swap(a[j][k], a[j+1][k]);
}

double fractional(double a[][3], int n, double cap){
    double total=0;
    for(int i=0;i<n;i++){
        if(cap>=a[i][0]){
            total+=a[i][1];
            cap-=a[i][0];
        }else{
            total+=a[i][2]*cap;
            break;
        }
    }
    return total;
}

int main(){

    const int n=3;
    double items[n][3], case1[n][3], case2[n][3], case3[n][3];

    random_device rd;
    mt19937 gen(rd() + steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> wdist(1,20);
    uniform_int_distribution<> pdist(10,100);

    for(int i=0;i<n;i++){
        items[i][0]=wdist(gen);
        items[i][1]=pdist(gen);
        items[i][2]=items[i][1]/items[i][0];
    }

    cout<<"Generated items (Weight Profit Ratio):\n";
    for(int i=0;i<n;i++)
        cout<<items[i][0]<<" "<<items[i][1]<<" "<<items[i][2]<<endl;

    double capacity;
    cout<<"\nEnter capacity: ";
    cin>>capacity;

    copyMatrix(items,case1,n);
    copyMatrix(items,case2,n);
    copyMatrix(items,case3,n);

    sortMinWeight(case1,n);
    sortMaxProfit(case2,n);
    sortMaxRatio(case3,n);

    double p1=fractional(case1,n,capacity);
    double p2=fractional(case2,n,capacity);
    double p3=fractional(case3,n,capacity);

    cout<<"\nCase 1: Minimum Weight\n" << p1 << endl;
    cout<<"Case 2: Maximum Profit\n" << p2 << endl;
    cout<<"Case 3: Maximum P/W Ratio\n" << p3 << endl;

    return 0;
}
