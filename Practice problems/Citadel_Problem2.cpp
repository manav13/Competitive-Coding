// Citadel - Disk Space analysis
#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> space, int index, int x) {
    int min = space[index];
    for(int i=index+1; i<index+x; i++) {
        if(space[index] < min) min = space[index];
    }
    return min;
}

int compute(vector<int> space, int x) {
    int size = space.size();
    int max = 0;
    for(int i=0; i<size-x; i++) {
        // if(space[i] < min) min = space[i];
        // if(min > max) max = min;
        int min = findMin(space, i, x);
        if(min > max) max = min;
    }
    return max;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> space;

    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        space.push_back(temp);
    }

    cout << compute(space, x) << endl;
}