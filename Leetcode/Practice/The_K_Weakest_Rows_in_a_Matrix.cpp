#include<bits/stdc++.h>
using namespace std;

int countOnes(vector<int> num) {
    int count = 0;
    for(auto i : num) {
        if(i==1) count++;
    }
    return count;
}

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int rows = mat.size();
    
    // RowID, SoldierCount
    vector<pair<int, int>> numSoldiers;
    
    for(int i=0; i<rows; i++) {
        numSoldiers.push_back({i, countOnes(mat[i])});
    }
    
    sort(numSoldiers.begin(), numSoldiers.end(), [] (auto &a, auto &b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    
    vector<int> ans;
    for(int i=0; i<k; i++) {
        ans.push_back(numSoldiers[i].first);
    }
    return ans;
}

int main() {
    return 0;
}