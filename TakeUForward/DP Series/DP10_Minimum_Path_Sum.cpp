class Solution {
public:

    int findMinPath(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        if(i<0 || j<0) {
            return INT_MAX;
        }

        if(i == 0 && j == 0) {
            return grid[i][j];
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = findMinPath(grid, i-1, j, dp);
        int left = findMinPath(grid, i, j-1, dp);

        dp[i][j] = grid[i][j] + min(up, left);
        
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return findMinPath(grid, m-1, n-1, dp);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) {
                    dp[i][j] = grid[i][j];
                }
                else {
                    int up = INT_MAX, left = INT_MAX;
                    if(i>0) {
                        up = dp[i-1][j];
                    }
                    if(j>0) {
                        left = dp[i][j-1];
                    }
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};