class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<vector<int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }

        int minTime = 0;
        vector<vector<int>> directions = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        while(!q.empty()) {
            vector<int> node = q.front();
            q.pop();

            for(auto dir : directions) {
                int newRow = node[0] + dir[0];
                int newCol = node[1] + dir[1];
                int newLevel = node[2]+1;
                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n) {
                    if(grid[newRow][newCol] == 1) {
                        q.push({newRow, newCol, newLevel});
                        grid[newRow][newCol] = 2;
                        minTime = max(minTime, newLevel);
                    }
                }
            }
        }

        // Check if there are any fresh oranges
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minTime;
    }
};