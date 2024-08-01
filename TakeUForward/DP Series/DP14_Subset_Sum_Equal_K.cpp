#include<bits/stdc++.h>
using namespace std;

bool solution(int index, int target, vector<int> &nums, vector<vector<int>> &dp) {
    if(target < 0) {
        return false;
    }
    if(target == 0) {
        return true;
    }
    if(index == 0) {
        return nums[index] == target;
    }

    if(dp[index][target] != -1 ){
        return dp[index][target] == 1;
    }

    bool notPick = solution(index-1, target, nums, dp);
    bool pick = solution(index-1, target-nums[index], nums, dp);

    if(notPick || pick) {
        dp[index][target] = 1;
    }
    else {
        dp[index][target] = 0;
    }

    return dp[index][target] == 1;
}

bool subsetSumToK(vector<int> &nums, int target) {
    int size = nums.size();
    vector<vector<int>> dp(size, vector<int>(target+1, -1));
    // return solution(size-1, target, nums, dp);

    for(int i=0; i<size; i++) {
        for(int k=0; k<=target; k++) {
            if(k == 0) {
                dp[i][k] = 1;
            }
            else if(i == 0) {
                dp[i][k] = (nums[i] == k) ? 1 : 0; 
            }
            else {
                bool notPick = dp[i-1][k];
                bool pick = false;

                if(k-nums[i] >= 0) {
                    pick = dp[i-1][k-nums[i]];
                }
                
                dp[i][k] = (notPick || pick) ? 1 : 0;
            }
        }
    }

    return dp[size-1][k];
}

int main() {
    vector<int> nums = {1, 3, 9, 4};
    int target = 3;
    cout << subsetSumToK(nums, target) << end;

    return 0;
}