class Solution {
public:

    bool detectCycleUsingBFS(int i, int j, vector<vector<char>> grid, vector<vector<int>> &visited, int m, int n) {
        // {curI, curJ, parI, parJ}
        queue<vector<int>> q;
        q.push({i, j, -1, -1});
        visited[i][j] = 1;

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
                int newI = node[0] + dir[0];
                int newJ = node[1] + dir[1];
                int parI = node[2];
                int parJ = node[3];

                if(newI>=0 && newJ>=0 && newI<m && newJ<n && grid[newI][newJ] == grid[i][j]) {
                    if(!visited[newI][newJ]) {
                        visited[newI][newJ] = 1;
                        q.push({newI, newJ, node[0], node[1]});
                    }
                    else if(!(newI == parI && newJ == parJ)) {
                        return true;
                    }
                }

            }
        }
        return false;
    }

    bool detectCyclesUsingDFS(int i, int j, int parI, int parJ, vector<vector<char>> grid, vector<vector<int>> visited, vector<vector<int>> directions, int m, int n) {

        visited[i][j] = 1;
        bool ans = false;
        for(auto dir : directions) {
            int newI = i + dir[0];
            int newJ = j + dir[1];

            if(newI>=0 && newJ>=0 && newI<m && newJ<n && grid[newI][newJ] == grid[i][j]) {
                if(!(newI == parI && newJ == parJ)) {
                    if(!visited[newI][newJ]) {
                        ans = ans || detectCyclesUsingDFS(newI, newJ, i, j, grid, visited, directions, m, n);
                    }
                    else {
                        return true;
                    }
                }
            }
        }
        return ans;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> directions = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        bool ans = false;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j]) {
                    // ans = ans || detectCycleUsingBFS(i, j, grid, visited, m, n);
                    ans = ans || detectCycleUsingDFS(i, j, -1, -1, grid, visited, m, n);
                }
            }
        }

        return ans;
    }
};