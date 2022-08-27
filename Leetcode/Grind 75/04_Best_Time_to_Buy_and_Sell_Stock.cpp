#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int currProfit = 0;
        
        for(int i=1; i<prices.size(); i++) {
            int profit = prices[i] - prices[i-1];
            if(currProfit + profit < 0)
                currProfit = 0;
            else 
                currProfit += profit;
            maxProfit = maxProfit < currProfit ? currProfit : maxProfit;
        }
        return maxProfit;
    }
};

int main() {
    return 0;
}