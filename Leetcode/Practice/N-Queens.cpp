#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n) {
    // Only check for left, left-top, left-bottom direction
    
    // Checking for left direction
    for(int c=col-1; c>=0; c--) {
        if(board[row][c] == 'Q') return false;
    }
    
    // Checking for left-top direction
    int r = row-1, c = col-1;
    while(r>=0 && c>=0) {
        if(board[r][c] == 'Q') return false;
        r--;
        c--;
    }
    
    // Checking for left-bottom direction
    r = row+1, c = col-1;
    while(r<n && c>=0) {
        if(board[r][c] == 'Q') return false;
        r++;
        c--;
    }
    
    return true;
}

void solve(vector<string>& board, int n, int col, vector<vector<string>>& output) {
    if(col == n) {
        output.push_back(board);
        return;
    }
    
    for(int row=0; row<n; row++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(board, n, col+1, output);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> output;
    vector<string> board (n, string(n, '.'));
    
    solve(board, n, 0, output);
    return output;
}

int main() {
    return 0;
}