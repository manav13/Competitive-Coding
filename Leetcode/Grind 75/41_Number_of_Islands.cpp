#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void bfs(int r, int c, vector<vector<bool>> &visited, int rows, int cols, vector<vector<char>> grid) {
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<vector<int>> dirs = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        while(!q.empty()) {
            int curR = q.front().first, curC = q.front().second;
            q.pop();
            
            for(auto dir : dirs) {
                int newR = curR + dir[0], newC = curC + dir[1];
                
                if(newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] == '1' && !visited[newR][newC]) {
                    visited[newR][newC] = true;
                    q.push({newR, newC});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(grid[r][c] == '1' && !visited[r][c]) {
                    visited[r][c] = true;
                    bfs(r, c, visited, rows, cols, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};

int main() {
    return 0;
}