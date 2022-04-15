#include<bits/stdc++.h>
using namespace std;

void findSubsets(vector<int> nums, int index, int size, vector<int>& ds, vector<vector<int>>& output) {
    output.push_back(ds);
    
    for(int i=index; i<size; i++) {
        if(i>index && nums[i] == nums[i-1]) {
            continue;
        }
        ds.push_back(nums[i]);
        findSubsets(nums, i+1, size, ds, output);
        ds.pop_back();
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> ds;
    vector<vector<int>> output;
    int size = nums.size();
    
    sort(nums.begin(), nums.end());
    
    findSubsets(nums, 0, size, ds, output);
    return output;
}

int main() {
    return 0;
}