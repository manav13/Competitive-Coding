#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> matrix, int frameSize) {
    int row = matrix.size(), col = matrix[0].size();

    vector<int> sumOfFrames;
    vector<pair<int, int>> indexes;
    for(int i=0; i<=row-frameSize; i++) {
        for(int j=0; j<=col-frameSize; j++) {
            int sum = 0;
            for(int r=i; r<i+frameSize; r++) {
                for(int c=j; c<j+frameSize; c++) {
                    if(r == i || r == i+frameSize-1 || c == j || c == j+frameSize-1) {
                        sum += matrix[r][c];
                    }
                }
            }
            sumOfFrames.push_back(sum);
            indexes.push_back({i, j});
        }
    }

    int maxSum = *max_element(sumOfFrames.begin(), sumOfFrames.end());
    set<int> nums;

    for(int i=0; i<sumOfFrames.size(); i++) {
        if(sumOfFrames[i] == maxSum) {

            int r = indexes[i].first;
            int c = indexes[i].second;

            for(int k=r; k<r+frameSize; k++) {
                for(int l=c; l<c+frameSize; l++) {
                    if(k == r || k == r+frameSize-1 || l == c || l == c+frameSize-1)
                        nums.insert(matrix[k][l]);
                }
            }
            
        }
    }
    int finalSum = 0;
    for(auto n : nums) {
        finalSum += n;
    }
    return finalSum;
}

int main() {

    vector<vector<int>> matrix = {
        {9,7,8,9,2},
        {6,9,9,6,1},
        {4,10,1,3,10},
        {18,2,3,9,3},
        {4,6,8,5,21}
    };
    int frameSize = 3;
    cout << solution(matrix, frameSize) << endl;
    return 0;
}