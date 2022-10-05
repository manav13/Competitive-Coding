#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void recursionSum(int i, vector<int> candidates, int target, vector<vector<int>>& output, vector<int>& ds) {
        if(i == candidates.size() || target <= 0) {
            if(target == 0) output.push_back(ds);
            return;
        }
        
        // Take condition
        target -= candidates[i];
        ds.push_back(candidates[i]);
        recursionSum(i, candidates, target, output, ds);
        
        ds.pop_back();
        target += candidates[i];
        
        // Not Take condition
        recursionSum(i+1, candidates, target, output, ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<int> s(candidates.begin(), candidates.end());
        vector<int> uniqueCandidates(s.begin(), s.end());
        
        vector<vector<int>> output;
        vector<int> ds;
        
        recursionSum(0, uniqueCandidates, target, output, ds);
        return output;
    }
};

int main() {
    return 0;
}