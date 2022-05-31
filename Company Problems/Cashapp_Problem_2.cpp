#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> towers) {
    int size = towers.size();
    int incrCount = 0, decrCount = 0;

    // Make array increasing
    vector<int> t1 = towers;
    vector<int> t2 = towers;
    for(int i=1; i<size; i++) {
        if(t1[i] < t1[i-1]) {
            int diff = (t1[i]-t1[i-1])+1;
            incrCount += diff;
            t1[i] += diff;
        }
    }
    for(int i=size-2; i>=0; i--) {
        int diff = t1[i+1] - t1[i];
        if(diff > 1) {
            incrCount += diff - 1;
            t1[i] += diff - 1;
        }
    }

    // Make array decreasing
    for(int i=0; i<size-1; i++) {
        if(t2[i] < t2[i+1]) {
            int diff = t2[i+1] - t2[i] + 1;
            decrCount += diff;
            t2[i] += diff;
        }
    }
    for(int i=1; i<size; i++) {
        int diff = t2[i] - t2[i-1];
        if(diff > 1) {
            decrCount += diff - 1;
            t2[i] += diff - 1;
        }
    }

    return incrCount < decrCount ? incrCount : decrCount;
}

int main() {

    int n;
    cin >> n;
    vector<int> towers;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        towers.push_back(temp);
    }
    cout << solution(towers) << endl;
    return 0;
}