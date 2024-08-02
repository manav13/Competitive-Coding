class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &visited, vector<vector<int>> &directions, int &m, int &n) {
        visited[i][j] = 1;
        for(auto dir : directions) {
            int r = i + dir[0];
            int c = j + dir[1];

            if(r>=0 && c>=0 && r<m && c<n && board[r][c] == 'O' && !visited[r][c]) {
                // visited[r][c] = 1;
                dfs(r, c, board, visited, directions, m, n);
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        vector<vector<int>> directions = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };

        // Row = 0 && row = m-1
        for(int col=0; col<n; col++) {
            if(board[0][col] == 'O' && !visited[0][col]) {
                dfs(0, col, board, visited, directions, m, n);
            }
            if(board[m-1][col] == 'O' && !visited[m-1][col]) {
                dfs(m-1, col, board, visited, directions, m, n);
            }
        }

        // Col = 0 && Col = n-1
        for(int row=0; row<m; row++) {
            if(board[row][0] == 'O' && !visited[row][0]) {
                dfs(row, 0, board, visited, directions, m, n);
            }
            if(board[row][n-1] == 'O' && !visited[row][n-1]) {
                dfs(row, n-1, board, visited, directions, m, n);
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(visited[i][j] == 1) {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};