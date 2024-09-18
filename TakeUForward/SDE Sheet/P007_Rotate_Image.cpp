class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Brute Force TC = O(n2) SC = O(n2)
        // int n = matrix.size();
        // vector<vector<int>> ans(n, vector<int>(n));

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         ans[j][n-1-i] = matrix[i][j];
        //     }
        // }
        // matrix = ans;

        // Optimal way TC = O(N2)  SC = O(1)
        // Transpose and Reverse the column arrays

        // Transpose logic
        int n = matrix.size();
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse logic
        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};