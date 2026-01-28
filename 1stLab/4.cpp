// Permutation Generator

#include<iostream>
using namespace std;

void P(string &input, int first, int last){
    if (first == last) {
        cout << input << endl;
    } else {
        for (int i = first; i <= last; i++){
            swap(input[i], input[first]);
            P(input, first+1, last);
            swap(input[i], input[first]);
        }
    }
}

int main(){
    string input = "bat";
    int num = input.size();

    cout << "All possible permutations of word " << input << " are:" << endl;
    P(input, 0, num-1);

    return 0;
}