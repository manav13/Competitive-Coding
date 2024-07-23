int findMinPath(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>> &dp) {

    if(i < 0 || j < 0 || i >= n || j >= n) {
        return 1e9;
    }

    if(i == 0) {
        return matrix[i][j];
    }

    if(dp[i][j] != 1e9) {
        return dp[i][j];
    }

    int path1 = findMinPath(i-1, j-1, n, matrix, dp);
    int path2 = findMinPath(i-1, j, n, matrix, dp);
    int path3 = findMinPath(i-1, j+1, n, matrix, dp);

    return dp[i][j] = matrix[i][j] + min(path1, min(path2, path3));
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int ans = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    // for(int j=0; j<n; j++) {
    //     ans = min(ans, findMinPath(n-1, j, n, matrix, dp));
    // }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==0) {
                dp[i][j] = matrix[i][j];
            }
            else {
                int path1 = 1e9;
                int path2 = dp[i-1][j];
                int path3 = 1e9;

                if(j>0) {
                    path1 = dp[i-1][j-1];
                }
                if(j<n-1) {
                    path3 = dp[i-1][j+1];
                }
                dp[i][j] = matrix[i][j] + min(path1, min(path2, path3));
            }
        }
    }

    for(int j=0; j<n; j++) {
        ans = min(ans, dp[n-1][j]);
    }

    return ans;
}