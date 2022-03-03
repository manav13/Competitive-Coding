#include<bits/stdc++.h>
using namespace std;

void getSubsequence(vector<int> candidates, int index, int target, vector<int> ds, vector<vector<int>>& result, int size) {
    // Base Case
    if(target == 0) {
        result.push_back(ds);
        return;
    }
    
    // Loop through the possible recursions
    for(int i=index; i<size; i++) {
        if(target < candidates[i]) break;
        if(i>index && candidates[i] == candidates[i-1]) continue;
        ds.push_back(candidates[i]);
        getSubsequence(candidates, i+1, target-candidates[i], ds, result, size);
        ds.pop_back();
    }
    
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> ds;
    int size = candidates.size();
    getSubsequence(candidates, 0, target, ds, result, size);
    return result;
}