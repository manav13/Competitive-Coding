#include<bits/stdc++.h>
using namespace std;

void combinationSumRecursion(vector<int>& candidates, int ind, int target, int size, vector<int> &ds, set<vector<int>> &midResult) {

    if(target < 0 || ind >= size) {
        return;
    }
    if(target == 0) {
        midResult.insert(ds);
        return;
    }

    // Take case
    ds.push_back(candidates[ind]);
    combinationSumRecursion(candidates, ind+1, target-candidates[ind], size, ds, midResult);
    ds.pop_back();

    // Not take case
    combinationSumRecursion(candidates, ind+1, target, size, ds, midResult);

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    set<vector<int>> midResult;
    vector<int> ds;

    sort(candidates.begin(), candidates.end());
    combinationSumRecursion(candidates, 0, target, candidates.size(), ds, midResult);
    
    vector<vector<int>> result;
    for(auto arr : midResult) {
        result.push_back(arr);
    }

    return result;
}

int main() {
    vector<int> candidates = {2,5,2,1,2};
    vector<vector<int>> result = combinationSum2(candidates, 5);

    for(auto arr : result) {
        cout << "[";

        for(auto num : arr) {
            cout << num << ", ";
        }

        cout << "]" << endl;
    }

    return 0;
}