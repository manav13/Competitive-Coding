#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    
    for(int i=0; i<row; i++) {
        if(matrix[i][0] <= target && matrix[i][col-1] >= target) {
            return binary_search(matrix[i].begin(), matrix[i].end(), target);
        }
    }
    return false;
}

int main() {
    return 0;
}