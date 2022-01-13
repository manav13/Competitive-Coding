#include<bits/stdc++.h>
using namespace std;

pair<int, int> maxValueSeen(vector<int> &arr, int index, int size) {
    pair<int, int> maxValue = {arr[index], index};
    
    for(int i=index+1; i<size; i++) {
        if(arr[i] >= maxValue.first) {
            maxValue.first = arr[i];
            maxValue.second = i;
        }
    }
    return maxValue;
}

void assignNum(vector<int> &arr, int start, int end, int value) {
    for(int i=start; i<end; i++) {
        arr[i] = value;
    }
}

vector<int> replaceElements(vector<int>& arr) {
    int size = arr.size();
    if(size==1) {
        arr[0] = -1;
        return arr;
    }
    for(int i=0; i<size; i++) {
        pair<int, int> maxValue = maxValueSeen(arr, i+1, size);
        assignNum(arr, i, maxValue.second, maxValue.first);
        i = maxValue.second-1;
    }
    arr[size-1] = -1;
    return arr;
}

int main() {
    return 0;
}