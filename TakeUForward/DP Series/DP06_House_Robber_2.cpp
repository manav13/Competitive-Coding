#include<bits/stdc++.h>
using namespace std;

int findMaxSum(vector<int>& nums, int index, int size, bool flag, map<pair<int, bool>, int> &dp) {
    if(index < 0) {
        return 0;
    }
    
    if(index == 0) {
        if(flag) {
            return 0;
        }
        else {
            return nums[index];
        }
    }

    if(dp.find({index, flag}) != dp.end()) {
        return dp[{index, flag}];
    }

    if(index == size-1) {
        int pick = nums[index] + findMaxSum(nums, index-2, size, true, dp);
        int notPick = findMaxSum(nums, index-1, size, false, dp);

        return max(pick, notPick);
    }
    
    int pick = nums[index] + findMaxSum(nums, index-2, size, flag, dp);
    int notPick = findMaxSum(nums, index-1, size, flag, dp);

    dp[{index, flag}] = max(pick, notPick);
    return dp[{index, flag}];
}

int findMaximumSum(vector<int> nums) {
    int size = nums.size();
    vector<int> dp(size, 0);
    
    dp[0] = max(0, nums[0]);
    for(int i=1; i<size; i++) {
        int pick = nums[i];
        if(i>1)
            pick += dp[i-2]; 
        int notPick = dp[i-1];
        dp[i] = max(pick, notPick);
    }
    return dp[size-1];
}

int rob(vector<int>& nums) {
    int size = nums.size();
    // vector<int> dp(size, -1);
    // map<pair<int, bool>, int> dp;
    // return findMaxSum(nums, size-1, size, false, dp);

    if(size == 1)
        return max(0,nums[0]);
    vector<int> temp1, temp2;
    for(int i=0; i<size; i++) {
        if(i != 0) temp1.push_back(nums[i]);
        if(i != size-1) temp2.push_back(nums[i]);
    }

    return max(findMaximumSum(temp1), findMaximumSum(temp2));
}