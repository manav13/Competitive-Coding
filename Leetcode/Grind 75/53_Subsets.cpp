#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void subsetHelper(vector<int> nums, int i, int size, vector<int> &ds, vector<vector<int>> &output) {
        if(i == size) {
            output.push_back(ds);
            return;
        }
        
        // Take condition
        ds.push_back(nums[i]);
        subsetHelper(nums, i+1, size, ds, output);
        ds.pop_back();
        
        // Do not take condition
        subsetHelper(nums, i+1, size, ds, output);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> output;
        
        int size = nums.size();
        subsetHelper(nums, 0, size, ds, output);
        return output;
    }
};

int main() {
    return 0;
}