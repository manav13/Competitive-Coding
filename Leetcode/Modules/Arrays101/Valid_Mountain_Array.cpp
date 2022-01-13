#include<bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int>& arr) {
    int size = arr.size();
    if(size<3 || arr[1] < arr[0]) return false;
    
    bool isIncreasing = true;
    
    for(int i=1; i<size; i++) {
        if(arr[i] == arr[i-1]) return false;
        if(isIncreasing) {
            if(arr[i] > arr[i-1]) continue;
            else {
                isIncreasing = false;
            }
        }
        else {
            if(arr[i] > arr[i-1]) return false;
        }
    }
    if(isIncreasing) return false;
    return true;
}

int main() {
    return 0;
}