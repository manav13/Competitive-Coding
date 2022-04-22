#include<bits/stdc++.h>
using namespace std;

int getNumOfFlips(vector<int> items, int expected) {
    int flipCount = 0;

    for(int i=0; i<items.size(); i++) {
        while(items[i]%2!=expected) {
            items[i] /= 2;
            flipCount++;
        }
        expected = (expected == 0) ? 1 : 0;
    }
    return flipCount;
}

int getMinimumOperations(vector<int> items) {
    return min(getNumOfFlips(items, 0), getNumOfFlips(items, 1));
}

int main() {
    vector<int> items = {6,5,9,7,3};
    cout << solution(items) << endl;
    return 0;
}