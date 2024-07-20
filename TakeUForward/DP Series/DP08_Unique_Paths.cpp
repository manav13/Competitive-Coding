class Solution {
public:

    int findTotalPaths(int i, int j, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) {
            return 0;
        }

        if(i == 0 && j == 0) {
            return 1;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        return dp[i][j] = findTotalPaths(i-1, j, dp) + findTotalPaths(i, j-1, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return findTotalPaths(m-1, n-1, dp);

        for(int i=0; i<m; i++) {
            dp[i][0] = 1;
        }

        for(int j=0; j<n; j++) {
            dp[0][j] = 1;
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};