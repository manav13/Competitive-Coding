class Solution {
public:

    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited, int m, int n) {
        queue<pair<int,int>> q;
        q.push({i, j});
        visited[i][j] = 1;

        vector<vector<int>> directions = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };

        while(!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();

            for(auto dir : directions) {
                int newI = node.first + dir[0];
                int newJ = node.second + dir[1];

                if(newI >= 0 && newJ >= 0 && newI < m && newJ < n) {
                    if(!visited[newI][newJ] && grid[newI][newJ] == '1') {
                        q.push({newI, newJ});
                        visited[newI][newJ] = 1;
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int numOfIslands = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    numOfIslands++;
                    bfs(i, j, grid, visited, m, n);
                }
            }
        }

        return numOfIslands;
    }
};