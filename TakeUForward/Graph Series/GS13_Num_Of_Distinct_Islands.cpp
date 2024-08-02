#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> grid, vector<vector<int>> &visited, vector<vector<int>> directions, int m, int n, int orgRow, int orgCol, vector<pair<int, int>> &path) {
    visited[i][j] = 1;
    path.push_back({i-orgRow, j-orgCol});

    for(auto dir : directions) {
        int r = i + dir[0];
        int c = j + dir[1];

        if(r>=0 && c>=0 && r<m && c<n && !visited[r][c] && grid[r][c] == 1) {
            dfs(r, c, grid, visited, directions, m, n, orgRow, orgCol, path);
        }
    }
}

int numOfDistinctIslands(vector<vector<int>> grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<vector<int>> directions = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };

    unordered_set<vector<pair<int, int>>> st;

    // land = 1 and water = 0
    // Iterate through all the land cells using DFS
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j] && grid[i][j] == 1) {
                // to store the pattern
                vector<pair<int, int>> path;
                dfs(i, j, grid, visited, direction, m, n, i, j, path);
                st.push(path);
            }
        }
    }

    return st.size();
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(m, vector<int>(n, -1));

    cout << numOfDistinctIslands(grid) << endl;

    return 0;

}