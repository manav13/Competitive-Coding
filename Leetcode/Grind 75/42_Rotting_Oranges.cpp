#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int minutes = 0, numFreshOranges = 0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)
                    numFreshOranges++;
            }
        }
        if(numFreshOranges == 0)
            return 0;
        vector<vector<int>> dirs = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        while(!q.empty()) {
            int size = q.size();
            minutes++;
            
            while(size--) {
                int curR = q.front().first, curC = q.front().second;
                q.pop();
                
                for(auto dir : dirs) {
                    int newR = curR + dir[0], newC = curC + dir[1];
                    if(newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] == 1) {
                        grid[newR][newC] = 2;
                        numFreshOranges--;
                        
                        q.push({newR, newC});
                    }
                }
            }
        }
        return numFreshOranges == 0 ? minutes-1 : -1;
    }
};

int main() {
    return 0;
}