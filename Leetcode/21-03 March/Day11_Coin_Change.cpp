#include<bits/stdc++.h>
using namespace std;

void findCoins(int index, int amount, vector<int>& coins, vector<int>& a, vector< vector<int> >& result) {
    if(amount == 0) {
        result.push_back(a);
        return;
    }

    if(index == coins.size()) {
        if(amount == 0) {
            result.push_back(a);
        }
        return;
    }

    // Pick up the coin
    if(coins[index] <= amount) {
        a.push_back(coins[index]);
        findCoins(index, amount - coins[index] , coins, a, result);
        a.pop_back();
    }

    // Dont pick up coin
    findCoins(index+1, amount, coins, a, result);
    return;
}

int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    else {
        vector<int> a;
        vector< vector<int> > result;
        findCoins(0, amount, coins, a, result);
        int min = result[0].size();
        for(auto it : result) {
            int size = it.size();
            if(min > size) min = size;
        }
        return min;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;
    // sort(coins.begin(), coins.end(), [] 
    // (const int& first, const int& second) {
    //     return first > second;
    // });

    cout << coinChange(coins, amount) << endl;
    return 0;
}