#include<bits/stdc++.h>
using namespace std;

void rightShift(vector<int> &arr, int size, int index) {
    for(int i=size-2; i>=index; i--) {
        arr[i+1] = arr[i];
    }
    if(index<size) arr[index] = 0;
}

void duplicateZeros(vector<int>& arr) {
    
    int size = arr.size();
    for(int i=0; i<size; i++) {
        if(arr[i] == 0) {
            rightShift(arr, size, i+1);
            i++;
        }
    }
}

int main() {
    return 0;
}