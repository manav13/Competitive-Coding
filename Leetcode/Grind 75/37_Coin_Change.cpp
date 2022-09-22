#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        
        // Base Case
        dp[0] = 0;
        
        for(int amt = 1; amt<=amount; amt++) {
            for(auto coinAmt : coins) {
                if(amt - coinAmt >= 0) {
                    dp[amt] = min(dp[amt], 1+dp[amt - coinAmt]);
                }
            }
        }
        
        return dp[amount] != amount+1 ? dp[amount] : -1;
    }
};

int main() {
    return 0;
}