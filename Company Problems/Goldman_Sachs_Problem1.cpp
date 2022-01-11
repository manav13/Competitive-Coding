#include<bits/stdc++.h>
using namespace std;

void update(vector<int> &arr, int n) {
    int temp = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > arr[i-1]) {
            int temp2 = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp2;
        }
        else break;
    }
}

int compute(int n, int process, vector<int> arr) {
    int seconds = 0;
    sort(arr.begin(), arr.end(), greater<int>());
    while(process>0) {
        process -= arr[0];
        arr[0] /= 2;
        // cout << arr[0] << endl;
        update(arr, n);
        seconds++;
    }
    return seconds;
}

// The above solution wont work if time complexity needed is less than O(n)
// Try with Priority Queue/Min-Max heap.

int main() {
    
    int n, processes;
    vector<int> arr;

    cin >> n >> processes;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int val = compute(n, processes, arr);
    cout << val << endl;
    return 0;
}