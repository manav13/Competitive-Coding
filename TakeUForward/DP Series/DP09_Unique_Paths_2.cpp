class Solution {
public:

    int findUniquePaths(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>> &dp) {
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1) {
            return 0;
        }
        
        if(i == 0 && j == 0) {
            return 1;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = findUniquePaths(obstacleGrid, i-1, j, dp) + findUniquePaths(obstacleGrid, i, j-1, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        // return findUniquePaths(obstacleGrid, m-1, n-1, dp);

        if(obstacleGrid[0][0] == 1) {
            return 0;
        }

        dp[0][0] = 1;

        for(int i=1; i<m; i++) {
            if(obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }
        for(int i=1; i<n; i++) {
            if(obstacleGrid[0][i] == 1) {
                break;
            }
            dp[0][i] = 1;
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};