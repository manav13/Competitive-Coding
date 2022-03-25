#include<bits/stdc++.h>
using namespace std;

void fillColor(vector<vector<int>>& image, int r, int c, int color, int m, int n, vector<vector<bool>> &isVisited) {
    if(r<0 || r>=m || c<0 || c>=n) return;
    if(isVisited[r][c]) return;
    int originalColor = image[r][c];
    image[r][c] = color;
    isVisited[r][c] = true;
    if(r>0 && image[r-1][c] == originalColor) {
        fillColor(image, r-1, c, color, m, n, isVisited);
        isVisited[r-1][c] = true;
    }
    if(c>0 && image[r][c-1] == originalColor) {
        fillColor(image, r, c-1, color, m, n, isVisited);
        isVisited[r][c-1] = true;
    }
    if(r<m-1 && image[r+1][c] == originalColor) {
        fillColor(image, r+1, c, color, m, n, isVisited);
        isVisited[r+1][c] = true;
    }
    if(c<n-1 && image[r][c+1] == originalColor) {
        fillColor(image, r, c+1, color, m, n, isVisited);
        isVisited[r][c+1] = true;
    }
    return;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int m = image.size();
    int n = image[0].size();
    vector<vector<bool>> isVisited(m, vector<bool> (n, false));
    fillColor(image, sr, sc, newColor, m, n, isVisited);
    return image;
}

int main() {
    return 0;
}