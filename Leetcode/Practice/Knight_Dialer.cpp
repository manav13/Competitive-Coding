#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> paths = {
            {4,6}, {6,8}, {7,9}, {4,8}, {3,9,0}, {}, {1,7,0}, {2,6}, {1,3}, {2,4}
        };
        int MOD = pow(10,9)+7;
        
        vector<vector<int>> dp(n+1, vector<int>(10, 0));
        
        for(int i=0; i<=9; i++) {
            dp[1][i] = 1;
        }
        
        for(int i=2; i<n+1; i++) {
            for(int j=0; j<10; j++) {
                for(auto path : paths[j]) {
                    dp[i][j] = (dp[i][j]%MOD + dp[i-1][path]%MOD)%MOD;
                }
                dp[i][j] %= MOD;
            }
        }
        
        int result = 0;
        for(int i=0; i<10; i++) {
            result = (result%MOD + dp[n][i]%MOD)%MOD;
        }
        return result%MOD;
    }
};

int main() {
    return 0;
}