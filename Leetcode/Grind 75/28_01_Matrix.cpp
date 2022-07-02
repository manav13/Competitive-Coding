#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Similar to rotten oranges problem
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int, int>> queue;
        
        // Add indexes of all the zeros to queue
        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                if(mat[row][col] == 0)
                    queue.push({row, col});
                else
                    mat[row][col] = -1;
            }
        }
        
        // Iterate through all the elements in queue
        // BFS traversal
        
        vector<pair<int, int>> directions = {
            {-1,0},
            {0, 1},
            {1, 0},
            {0,-1}
        };
        
        int level = 0;
        while(!queue.empty()) {
            int size = queue.size();
            level++;
            
            while(size-- > 0) {
                pair<int, int> cell = queue.front();
                queue.pop();
                for(auto dir : directions) {
                    int r = cell.first + dir.first;
                    int c = cell.second + dir.second;
                    
                    if(r<0 || c<0 || r==m || c==n || mat[r][c]!=-1)
                        continue;
                    
                    mat[r][c] = level;
                    queue.push({r,c});
                }
            }
        }
        return mat;
    }
};

int main() {
    return 0;
}