#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int n, vector<int>& arr, int start, int end) {
    
    if(start == end) {
        if(n == arr[start]) return true;
        else return false;
    }
    else if(start > end || end < start) return false;
    
    int index = (start+end)/2;
    if(n == arr[index]) return true;
    else {
        if(n < arr[index]) {
            return binarySearch(n, arr, start, index-1);
        }
        else {
            return binarySearch(n, arr, index+1, end);
        }
    }
}

bool checkIfExist(vector<int>& arr) {
    int size = arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0; i<size; i++) {
        int num = 2*arr[i];
        if(num == 0) {
            if(arr[i+1] == 0 || arr[i-1] == 0) return true;
        }
        else {
            if(binarySearch(num, arr, 0, size-1)) return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int i = 0;
    while(n) {
        cin >> arr[i];
        ++i;
        --n;
    }
    cout << checkIfExist(arr) << endl;
}