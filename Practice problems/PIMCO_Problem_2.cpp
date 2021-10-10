#include<bits/stdc++.h>
using namespace std;

int compute(vector<int> stockPrices, int k){
    int n = stockPrices.size();
    int count = 1;
    int ans = 0;
    for(int i=0; i<n-1; i++) {
        if(stockPrices[i] < stockPrices[i+1]) count++;
        else {
            if(count >= k) ans += count-k+1;
            count = 1;
        }
    }
    if(count >= k) ans += count-k+1;
    return ans;
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