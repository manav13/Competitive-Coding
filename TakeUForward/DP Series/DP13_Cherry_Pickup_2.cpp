class Solution {
public:

    int findMaxPath(int i, int j1, int j2, int rows, int cols, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        // 1st Base Case: Out of bound case
        if(j1<0 || j2<0 || j1 >= cols || j2 >= cols) {
            return -1e9;
        }

        // 2nd Base Case: last row
        if(i == rows-1) {
            if(j1 == j2) {
                return grid[i][j1];
            }
            else {
                return grid[i][j1] + grid[i][j2];
            }
        }

        if(dp[i][j1][j2] != -1e8) {
            return dp[i][j1][j2];
        }

        int ans = -1e8;
        // Explore all paths
        for(int dj1=-1; dj1<=1; dj1++) {
            for(int dj2=-1; dj2<=1; dj2++) {
                ans = max(ans, findMaxPath(i+1, j1+dj1, j2+dj2, rows, cols, grid, dp));
            }
        }

        if(j1 == j2) {
            ans += grid[i][j1];
        }
        else {
            ans += grid[i][j1] + grid[i][j2];
        }

        return dp[i][j1][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1e8)));
        // return findMaxPath(0, 0, cols-1, rows, cols, grid, dp);

        for(int i=rows-1; i>=0; i--) {
            for(int j1=0; j1<cols; j1++) {
                for(int j2=0; j2<cols; j2++) {

                    // Base Case
                    if(i == rows-1) {
                        if(j1 == j2) {
                            dp[i][j1][j2] = grid[i][j1];
                        }
                        else {
                            dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                        }
                    }
                    else {
                        int ans = -1e9;
                        for(int dj1=-1; dj1<=1; dj1++) {
                            for(int dj2=-1; dj2<=1; dj2++) {
                                
                                if(j1+dj1 >= 0 && j1+dj1 < cols && j2+dj2 >= 0 && j2+dj2 < cols) {
                                    ans = max(ans, dp[i+1][j1+dj1][j2+dj2]);
                                }
                                
                            }
                        }

                        if(j1 == j2) {
                            dp[i][j1][j2] = ans + grid[i][j1];
                        }
                        else {
                            dp[i][j1][j2] = ans + grid[i][j1] + grid[i][j2];
                        }
                    }
                }
            }
        }

        return dp[0][0][cols-1];
    }
};