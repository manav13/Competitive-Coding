#include<bits/stdc++.h>
using namespace std;

int findMaxSum(vector<int> nums, int index, vector<int> &dp) {
    if(index < 0) {
        return 0;
    }

    if(dp[index] != -1) {
        return dp[index];
    }

    int pick = nums[index] + findMaxSum(nums, index-2, dp);
    int notPick = findMaxSum(nums, index-1, dp);

    dp[index] = max(pick, notPick);
    return dp[index];
}

int main() {
    vector<int> nums = {-2, 4, 1, 44, -9};
    int size = nums.size();
    vector<int> dp(size, -1);
    // cout << findMaxSum(nums, size-1, dp) << endl;

    dp[0] = max(0, nums[0]);

    for(int i=1; i<size; i++) {
        int pick = nums[i];
        if(i>1) {
            pick += dp[i-2];
        }
        int notPick = dp[i-1];

        dp[i] = max(pick, notPick);
    }

    cout << dp[size-1] << endl;
    
    // Space Optimized
    int prev = max(0, nums[0]);
    int prev2 = 0;
    for(int i=1; i<size; i++) {
        int pick = nums[i];
        if(i>1) {
            pick += prev2;
        }

        int notPick = prev;
        int curI = max(pick, notPick);

        prev2 = prev;
        prev = curI;
    }

    cout << "Space Optimized: " << prev << endl;
}