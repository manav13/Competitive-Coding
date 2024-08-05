// Problem Name - Grid Climbing

#include<bits/stdc++.h>
using namespace std;

int countOnes(int row, vector<vector<int>> matrix, int n) {
    int count = 0;
    for(int col = 0; col < n; col++) {
        if(matrix[row][col] == 1) {
            count++;
        }
    }
    return count;
}

int numberOfConnections(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int prevOnes = countOnes(0, matrix, n);
    int ans = 0;
    for(int i=1; i<m; i++) {
        int numOfOnes = countOnes(i, matrix, n);
        if(numOfOnes == 0) {
            continue;
        }

        ans += (numOfOnes*prevOnes);
        prevOnes = numOfOnes;
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    cout << numberOfConnections(matrix) << endl;
}