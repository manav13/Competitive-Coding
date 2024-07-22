#include<bits/stdc++.h>
using namespace std;

int findMinPath(int index, int row, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
    if(index < 0 || index > row) {
        return 1e9;
    }
    if(row == 0) {
        return triangle[0][0];
    }

    if(dp[row][index] != 1e9) {
        return dp[row][index];
    }

    int path1 = findMinPath(index, row-1, triangle, dp);
    int path2 = findMinPath(index-1, row-1, triangle, dp);

    dp[row][index] = triangle[row][index] + min(path1, path2);

    return dp[row][index];
}

int minimumTotal(vector<vector<int>>& triangle) {
    int row = triangle.size();
    // int ans = 1e9;

    // vector<vector<int>> dp(row, vector<int>(row, 1e9));

    // for(int j=0; j<row; j++) {
    //     ans = min(ans, findMinPath(j, row-1, triangle, dp));
    // }

    // return ans;

    vector<vector<int>> dp(row, vector<int>(row, 1e9));
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<=i; j++) {
            if(i == 0) {
                dp[0][0] = triangle[0][0];
            }
            else {
                int path1 = dp[i-1][j];
                int path2 = 1e9;

                if(j>0) {
                    path2 = dp[i-1][j-1];
                }

                dp[i][j] = triangle[i][j] + min(path1, path2);
            }
        }
    }

    int ans = 1e9;
    for(int col=0; col<row; col++) {
        ans = min(ans, dp[row-1][col]);
    }

    return ans;
}

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    cout << minimumTotal(triangle) << endl;
}