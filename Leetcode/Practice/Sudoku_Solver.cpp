#include<bits/stdc++.h>
using namespace std;

bool isSafe(char c, vector<vector<char>> board, int row, int col) {
    for(int i=0; i<9; i++) {
        // Check all columns
        if(board[row][i] == c) return false;
        
        // Check all rows
        if(board[i][col] == c) return false;
        
        // Check 3*3 sub-matrix
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board) {
    
    for(int row=0; row<9; row++) {
        for(int col=0; col<9; col++) {
            if(board[row][col] == '.') {
                for(char i='1'; i<='9'; i++) {
                    if(isSafe(i, board, row, col)) {
                        
                        board[row][col] = i;
                        if(solve(board)) return true;
                        else board[row][col] = '.';
                        
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

int main() {
    return 0;
}