#include<bits/stdc++.h>
using namespace std;

int compute(vector<int> arr) {
    int size = arr.size();
    bool prevParity = (arr[0]%2==0);
    int ans = -1;
    for(int i=1; i<size; i++) {
        bool curParity = (arr[i]%2==0);
        if(curParity == prevParity) {
            ans = i;
            break;
        }
        prevParity = curParity;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << compute(arr) << endl;
    return 0;
}