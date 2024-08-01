class Solution {
public:

    bool findSubset(int index, vector<int> nums, int target, vector<vector<int>> &dp) {

        if(index == 0) {
            return target == nums[0];
        }

        if(target == 0) {
            return true;
        }

        if(target <= 0) {
            return false;
        }

        if(dp[index][target] != -1) {
            return dp[index][target];
        }

        bool pick = findSubset(index-1, nums, target-nums[index], dp);

        bool notPick = pick || findSubset(index-1, nums, target, dp);

        return dp[index][target] = notPick;
 
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        for(auto num : nums) {
            sum += num;
        }

        if(sum%2 == 1) {
            return false;
        }

        int target = sum/2;
        vector<vector<int>> dp(size, vector<int>(target+1, -1));
        // return findSubset(size-1, nums, target, dp);

        for(int i=0; i<size; i++) {
            for(int j=0; j<=target; j++) {
                if(j == 0) {
                    dp[i][j] = 1;
                }
                if(i == 0) {
                    dp[i][j] = (nums[i] == j);
                }
                else {
                    bool pick = false;
                    if(j-nums[i] >= 0) {
                        pick = dp[i-1][j-nums[i]];
                    }

                    dp[i][j] = pick || dp[i-1][j];
                }
            }
        }

        return dp[size-1][target];
    }
};