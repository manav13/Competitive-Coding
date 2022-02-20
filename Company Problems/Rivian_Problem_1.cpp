// Name - Automobile Spare Parts (TC - 6/15)
#include<bits/stdc++.h>
using namespace std;

int findMaximumMoneyEarned(vector<int> cost, int x)
{
    int n = cost.size();
    vector<int> val(n);

    for(int i=0; i<n; i++) {
        val[i] = pow(2, i);
    }

    long long int dp[x + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i < n + 1; i++) {
        for (int w = x; w >= 0; w--) {
            if (cost[i - 1] <= w){
                dp[w] = (max(dp[w] % 1000000007, (dp[w - cost[i - 1]] + val[i - 1]) % 1000000007 )) % 1000000007;
            }
        }
    }
    return dp[x];
}

int main() {
    cout << findMaximumMoneyEarned({10,20,14,40,50}, 70) << endl;
    return 0;
}