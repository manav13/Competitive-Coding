// Problem - Counting Cars
#include<bits/stdc++.h>
using namespace std;

vector<int> countingCars(vector<int> numCars, vector<int> hourStartQ) {
    int size = numCars.size();
    vector<int> maxFreq (size, 1);
    int maxNum = numCars[size-1];
    unordered_map<int, int> hash;

    for(int i=size-1; i>=0; i--) {
        hash[numCars[i]]++;
        if(numCars[i] <= maxNum)
            maxFreq[i] = hash[maxNum];
        else {
            maxNum = numCars[i];
        }
    }

    vector<int> result;
    for(int i=0; i<hourStartQ.size(); i++) {
        result.push_back(maxFreq[hourStartQ[i]-1]);
    }
    return result;
}

int main() {
    vector<int> numCars = {2,2,2};
    vector<int> hourStartQ = {1,2,3};
    vector<int> result = countingCars(numCars, hourStartQ);
    for(int i=0; i<hourStartQ.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}