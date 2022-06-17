#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Kadane's Algorithm
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, currProfit = 0;
        for(int i=1; i<prices.size(); i++) {
            if(currProfit + prices[i] - prices[i-1] < 0) {
                if(maxProfit < currProfit) maxProfit = currProfit;
                currProfit = 0;
            }
            else currProfit += (prices[i] - prices[i-1]);
            
            maxProfit = maxProfit < currProfit ? currProfit : maxProfit;
        }
        return maxProfit;
    }
};

int main() {
    return 0;
}