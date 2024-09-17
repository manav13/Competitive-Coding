class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // vector<int> row(m, 1);
        // vector<int> col(n, 1);
        int row0 = 1;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) {
                        row0 = 0;
                    }
                    else {
                        matrix[i][0] = 0;
                    }
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0) {
            for(int i=0; i<m; i++) {
                matrix[i][0] = 0;
            }
        }

        if(row0 == 0) {
            for(int j=0; j<n; j++) {
                matrix[0][j] = 0;
            }
        }

    }
};