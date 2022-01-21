#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size(), n = mat[0].size();
    if(m*n != r*c) return mat;
    
    vector<vector<int>> ans(r, vector<int> (c));
    int row = 0, col = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(col == c) {
                col = 0;
                row++;
            }
            ans[row][col] = mat[i][j];
            col++;
        }
    }
    return ans;
}

int main() {
    return 0;
}