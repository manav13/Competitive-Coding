#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();
        
        int left = 0, right = n, top = 0, bottom = m;
        
        while(left < right && top < bottom) {
            
            // Right direction
            for(int i=left; i<right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            // Down direction
            for(int i=top; i<bottom; i++) {
                result.push_back(matrix[i][right-1]);
            }
            right--;
            
            if(left >= right || top >= bottom)
                break;

            // Left direction
            for(int i=right-1; i>=left; i--) {
                result.push_back(matrix[bottom-1][i]);
            }
            bottom--;

            // Up direction
            for(int i=bottom-1; i>=top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return result;
    }
};

int main() {
    return 0;
}