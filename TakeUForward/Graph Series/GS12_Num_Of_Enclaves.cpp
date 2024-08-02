class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &visited, vector<vector<int>> &directions, int &m, int &n, int &ans) {
        visited[i][j] = 1;
        ans += 1;
        for(auto dir : directions) {
            int r = i + dir[0];
            int c = j + dir[1];

            if(r>=0 && c>=0 && r<m && c<n && grid[r][c] == 1 && !visited[r][c]) {
                dfs(r, c, grid, visited, directions, m, n, ans);
            }
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        vector<vector<int>> directions = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };

        int ans = 0;

        // Row = 0 && row = m-1
        for(int col=0; col<n; col++) {
            if(grid[0][col] == 1 && !visited[0][col]) {
                dfs(0, col, grid, visited, directions, m, n, ans);
            }
            if(grid[m-1][col] == 1 && !visited[m-1][col]) {
                dfs(m-1, col, grid, visited, directions, m, n, ans);
            }
        }

        // Col = 0 && Col = n-1
        for(int row=0; row<m; row++) {
            if(grid[row][0] == 1 && !visited[row][0]) {
                dfs(row, 0, grid, visited, directions, m, n, ans);
            }
            if(grid[row][n-1] == 1 && !visited[row][n-1]) {
                dfs(row, n-1, grid, visited, directions, m, n, ans);
            }
        }

        int totalOnes = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) totalOnes += 1;
            }
        }

        return totalOnes - ans;
    }
};