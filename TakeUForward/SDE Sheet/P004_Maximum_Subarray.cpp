class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = 0;
        int size = nums.size();
        
        for(int i=0; i<size; i++) {
            if(curSum < 0) {
                curSum = 0;
            }
            curSum += nums[i];
            maxSum = maxSum < curSum ? curSum : maxSum;
        }

        return maxSum;
    }
};