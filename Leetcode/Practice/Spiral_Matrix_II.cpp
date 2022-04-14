#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int left = 0, right = n, top = 0, bottom = n;
    vector<vector<int>> output (n, vector<int> (n, 0));
    int count = 1;
    while(left<right && top<bottom) {
        
        // Left to Right
        for(int i=left; i<right; i++) {
            output[top][i] = count;
            count++;
        }
        top++;
        
        // Top to Bottom
        for(int i=top; i<bottom; i++) {
            output[i][right-1] = count;
            count++;
        }
        right--;
        
        // Right to Left
        for(int i=right-1; i>=left; i--) {
            output[bottom-1][i] = count;
            count++;
        }
        bottom--;
        
        // Bottom to Top
        for(int i=bottom-1; i>=top; i--) {
            output[i][left] = count;
            count++;
        }
        left++;
    }
    return output;
}

int main() {
    return 0;
}