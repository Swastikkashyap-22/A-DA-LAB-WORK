// Activity Selection Problem

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void swapAll(int id[], int start[], int finish[], int i, int j) {
    swap(id[i], id[j]);
    swap(start[i], start[j]);
    swap(finish[i], finish[j]);
}

void sortByFinish(int id[], int start[], int finish[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                swapAll(id, start, finish, i, j);
            }
        }
    }
}

void sortByDuration(int id[], int start[], int finish[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int d1 = finish[i] - start[i];
            int d2 = finish[j] - start[j];
            if (d1 > d2) {
                swapAll(id, start, finish, i, j);
            }
        }
    }
}

void pickActivities(int id[], int start[], int finish[], int n, int mode) {
    int tid[20], tstart[20], tfinish[20];

    for (int i = 0; i < n; i++) {
        tid[i] = id[i];
        tstart[i] = start[i];
        tfinish[i] = finish[i];
    }

    if (mode == 1) {
        sortByFinish(tid, tstart, tfinish, n);
        cout << "Strategy: Finish Time\n";
    } else {
        sortByDuration(tid, tstart, tfinish, n);
        cout << "Strategy: Shortest Duration\n";
    }

    cout << "Selected: A" << tid[0] << " ";
    int last = 0, count = 1;

    for (int i = 1; i < n; i++) {
        if (tstart[i] >= tfinish[last]) {
            cout << "A" << tid[i] << " ";
            last = i;
            count++;
        }
    }

    cout << "\nTotal = " << count << "\n\n";
}

int main() {
    int id[]     = {1,2,3,4,5,6,7,8,9,10};
    int start[]  = {0,3,4,5,8,11,12,15,16,1};
    int finish[] = {4,5,8,9,12,13,16,17,20,19};

    int n = 10;

    auto start_time = high_resolution_clock::now();
    pickActivities(id, start, finish, n, 1);
    pickActivities(id, start, finish, n, 2);
    auto end_time = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout << "Time taken = " << duration.count() << " microseconds";

    return 0;
}

