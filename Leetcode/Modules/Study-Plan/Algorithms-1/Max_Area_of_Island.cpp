#include<bits/stdc++.h>
using namespace std;

int islandArea(vector<vector<int>> grid, vector<vector<bool>> &isVisited, int r, int c, int m, int n) {
    if(r<0 || r>=m || c<0 || c>=n) return 0;
    if(isVisited[r][c]) return 0;
    int area = 1;
    isVisited[r][c] = true;
    if(r>0 && !isVisited[r-1][c] && grid[r-1][c]==1) {
        area += islandArea(grid, isVisited, r-1, c, m, n);
    }
    if(c>0 && !isVisited[r][c-1] && grid[r][c-1]==1) {
        area += islandArea(grid, isVisited, r, c-1, m, n);
    }
    if(r<m-1 && !isVisited[r+1][c] && grid[r+1][c]==1) {
        area += islandArea(grid, isVisited, r+1, c, m, n);
    }
    if(c<n-1 && !isVisited[r][c+1] && grid[r][c+1]==1) {
        area += islandArea(grid, isVisited, r, c+1, m, n);
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int nrows = grid.size();
    int ncols = grid[0].size();
    vector<vector<bool>> isVisited(nrows, vector<bool> (ncols, false));
    int maxArea = 0;
    for(int i=0; i<nrows; i++) {
        for(int j=0; j<ncols; j++) {
            if(grid[i][j] == 1 && !isVisited[i][j]) {
                int area = islandArea(grid, isVisited, i, j, nrows, ncols);
                maxArea = (area > maxArea) ? area : maxArea;
            }
        }
    }
    return maxArea;
}

int main() {
    return 0;
}