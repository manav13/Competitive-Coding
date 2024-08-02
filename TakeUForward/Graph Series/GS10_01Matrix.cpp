#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<vector<int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j, 0});
                    visited[i][j] = 1;
                }
            }
        }
        
        vector<vector<int>> directions = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };

        while(!q.empty()) {
            vector<int> node = q.front();
            q.pop();
            ans[node[0]][node[1]] = node[2];

            for(auto dir : directions) {
                int r = node[0] + dir[0];
                int c = node[1] + dir[1];
                int level = node[2] + 1;

                if(r >= 0 && c >= 0 && r < m && c < n && !visited[r][c]) {
                    visited[r][c] = 1;
                    q.push({r,c,level});
                }
            }

        }

        return ans;
}

int main() {

    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    updateMatrix(mat);

    return 0;

}