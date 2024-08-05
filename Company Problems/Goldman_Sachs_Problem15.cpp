// Problem name - Count connections in matrix

#include<bits/stdc++.h>
using namespace std;

int findCountOnes(int i, int j, vector<vector<int>> matrix, int m, int n) {
    // Right horizontal (0, 1);
    // right vertical (1, 1);
    // direct down (1, 0);
    // down left vertical (1, -1);

    vector<vector<int>> directions = {
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1}
    };
    int count = 0;
    for(auto dir : directions) {
        int row = i + dir[0];
        int col = j + dir[1];

        if(row >= 0 && col >= 0 && row < m && col < n && matrix[row][col] == 1) {
            count += 1;
        }
    }
    return count;
}

int countConnections(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == 1) {
                ans += findCountOnes(i, j, matrix, m, n);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 0, 1}
    };

    cout << countConnections(matrix) << endl;
}