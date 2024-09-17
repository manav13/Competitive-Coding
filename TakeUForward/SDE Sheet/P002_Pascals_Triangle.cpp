class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        for(int i=1; i<numRows; i++) {
            vector<int> row;
            row.push_back(1);

            for(int j=1; j<i; j++) {
                int num = triangle[i-1][j-1] + triangle[i-1][j];
                row.push_back(num);
            }

            row.push_back(1);
            triangle.push_back(row);
        }

        return triangle;
    }
};