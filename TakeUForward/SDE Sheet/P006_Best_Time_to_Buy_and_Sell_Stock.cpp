class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int curProfit = 0;

        for(int i=1; i<prices.size(); i++) {
            curProfit += prices[i] - prices[i-1];

            if(curProfit < 0) {
                curProfit = 0;
            }

            maxProfit = maxProfit < curProfit ? curProfit : maxProfit;
        }

        return maxProfit;
    }
};