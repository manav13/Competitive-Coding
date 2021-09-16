#include<bits/stdc++.h>
using namespace std;

int compute(vector<int> arr, int k) {
    int n = arr.size();
    int count = 0;

    sort(arr.begin(), arr.end());
    int i = 0;
    int j = n-1;

    while(i<j) {
        if(arr[i] + arr[j] == k) {
            while (i<j && arr[i]==arr[i+1]) {
                i++;
            }
            while(i<j && arr[j]==arr[j-1]) {
                j--;
            }
            count++;
            i++;
            j--;
        }
        else if(arr[i]+arr[j] < k) {
            i++;
        }
        else {
            j--;
        }
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr;

    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << compute(arr, k) << endl;

    return 0;
}