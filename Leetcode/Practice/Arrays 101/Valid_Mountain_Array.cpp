#include<bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int>& arr) {
    int size = arr.size();
    if(size >= 3) {
        if(arr[1] <= arr[0]) return false;
        else {
            int flag = 1;
            for(int i=2; i<size; i++) {
                if(arr[i] == arr[i-1]) return false;
                else if(flag==1 && arr[i] < arr[i-1]) {
                    flag = 0;
                }
                else if(flag==0) {
                    if(arr[i] > arr[i-1]) return false;
                }
            }
            if(flag == 1) return false;
            else return true;
        }
    }
    else return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<arr.size(); i++) {
        cin >> arr[i];
    }
    cout << validMountainArray(arr) << endl;
}