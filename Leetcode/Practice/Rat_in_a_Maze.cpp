#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> maze, int r, int c, int n, vector<string> &output, string &ds, vector<vector<int>> &visited) {
    if(r==n-1 && c==n-1) {
        output.push_back(ds);
        return;
    }
    
    // Directions - D, L, R, U

    // Down direction - Possible?
    if(r+1 < n && maze[r+1][c]==1 && visited[r+1][c]==0) {
        visited[r][c] = 1;
        ds.push_back('D');
        solve(maze, r+1, c, n, output, ds, visited);
        ds.pop_back();
        visited[r][c] = 0;
    }

    // Left Direction - Possible?
    if(c-1 > 0 && maze[r][c-1]==1 && visited[r][c-1]==0) {
        visited[r][c] = 1;
        ds.push_back('L');
        solve(maze, r, c-1, n, output, ds, visited);
        ds.pop_back();
        visited[r][c] = 0;
    }

    // Right Direction - Possible?
    if(c+1 < n && maze[r][c+1]==1 && visited[r][c+1]==0) {
        visited[r][c] = 1;
        ds.push_back('R');
        solve(maze, r, c+1, n, output, ds, visited);
        ds.pop_back();
        visited[r][c] = 0;
    }

    // Upward direction - Possible?
    if(r-1 > 0 && maze[r-1][c]==1 && visited[r-1][c]==0) {
        visited[r][c] = 1;
        ds.push_back('U');
        solve(maze, r-1, c, n, output, ds, visited);
        ds.pop_back();
        visited[r][c] = 0;
    }
}

vector<string> ratInAMaze(vector<vector<int>> maze) {
    vector<string> output;
    string ds;

    int n = maze.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));

    solve(maze, 0, 0, n, output, ds, visited);
    return output;
}

int main() {
    vector<vector<int>> maze {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> ans = ratInAMaze(maze);
    for(auto st : ans) {
        cout << st << endl;
    }
    return 0;
}