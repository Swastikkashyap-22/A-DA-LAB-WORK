// Permutation Generator

#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

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
    auto start = high_resolution_clock::now();
    P(input, 0, num-1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " milliseconds";

    return 0;
}