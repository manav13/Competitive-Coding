#include<bits/stdc++.h>
using namespace std;

int compute(vector<int> arr) {
    int size = arr.size();
    int count = size;
    for(int i=2; i<=size; i++) {
        for(int j=0; j<size-i+1; j++) {
            bool isConsistent = true;
            for(int k=j; k<j+i-1; k++) {
                if(arr[k]%2 == arr[k+1]%2) {
                    isConsistent = false;
                    break;
                }
            }
            if(isConsistent) count++;
        }
    }
    return count;
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << compute(arr) << endl;
    return 0;
}