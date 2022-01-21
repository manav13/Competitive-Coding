#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    // Maximum Sub array problem
    // Solve using Kadane's algorithm
    
    int size = prices.size();
    vector<int> newPrices;
    newPrices.push_back(0);
    for(int i=1; i<size; i++) {
        newPrices.push_back(prices[i] - prices[i-1]);
    }
    
    int maxProfit = 0, curProfit = 0;
    for(int i=0; i<size; i++) {
        if(curProfit + newPrices[i] < 0) curProfit = 0;
        else curProfit += newPrices[i];
        maxProfit = (maxProfit < curProfit ? curProfit : maxProfit);
    }
    return maxProfit;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << maxProfit(nums) << endl;
}