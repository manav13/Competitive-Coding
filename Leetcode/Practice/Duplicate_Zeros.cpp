#include<bits/stdc++.h>
using namespace std;

void insertZero(vector<int>& arr, int index, int size) {
    for(int i=size-2; i>=index; i--) {
        arr[i+1] = arr[i];
    }
    if (index!=size) arr[index] = 0;
}

void duplicateZeros(vector<int>& arr) {
    int size = arr.size();
    for(int i=0; i<size; i++) {
        if(arr[i] == 0) {
            insertZero(arr, i+1, size);
            ++i;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    duplicateZeros(arr);
    for(auto num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}