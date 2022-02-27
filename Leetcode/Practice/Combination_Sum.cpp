#include<bits/stdc++.h>
using namespace std;

void getSubsequence(vector<int> candidates, int index, int target, vector<int> ds, set<vector<int>> & result) {
    // Base Case
    if(target < 0) return;
    if(index == candidates.size()) {
        if(target == 0) {
            result.insert(ds);
        }
        return;
    }
    
    // Take condition recursion
    if(candidates[index] <= target) {
        ds.push_back(candidates[index]);
        getSubsequence(candidates, index, target-candidates[index], ds, result);
        ds.pop_back();
    }
    
    // Not take condition recursion
    getSubsequence(candidates, index+1, target, ds, result);
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    set<vector<int>> result;
    vector<int> ds;
    getSubsequence(candidates, 0, target, ds, result);
    vector<vector<int>> ans;
    for(auto it : result) {
        ans.push_back(it);
    }
    return ans;
}

int main() {
    return 0;
}