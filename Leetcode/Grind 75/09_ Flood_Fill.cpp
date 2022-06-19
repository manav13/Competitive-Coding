#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void floodFillRecursion(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& visited, int m, int n) {
        if(visited[sr][sc] || image[sr][sc] == color) return;
        
        visited[sr][sc] = 1;
        // Top
        if(sr > 0 && image[sr-1][sc] == image[sr][sc])
            floodFillRecursion(image, sr-1, sc, color, visited, m, n);
        // Right
        if(sc < n-1 && image[sr][sc+1] == image[sr][sc])
            floodFillRecursion(image, sr, sc+1, color, visited, m, n);
        // Bottom
        if(sr < m-1 && image[sr+1][sc] == image[sr][sc])
            floodFillRecursion(image, sr+1, sc, color, visited, m, n);
        // Left
        if(sc > 0 && image[sr][sc-1] == image[sr][sc])
            floodFillRecursion(image, sr, sc-1, color, visited, m, n);
        
        image[sr][sc] = color;
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int m = image.size(), n = image[0].size();
        vector<vector<int>> visited (m, vector<int> (n, 0));
        floodFillRecursion(image, sr, sc, color, visited, image.size(), image[0].size());
        return image;
    }
};

int main() {
    return 0;
}