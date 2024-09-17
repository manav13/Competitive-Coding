class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Algorithm intuition
        // Step 1: Find longest prefix
        // Step 2: Find a number who is the next smallest larger number
        // Step 3: arrange the rest of the numbers in sorted order

        // Find longest prefix
        int n = nums.size();

        int index = -1;
        for(int i=n-1; i>0; i--) {
            if(nums[i-1] < nums[i]) {
                index = i-1;
                break;
            }
        }

        // if index = -1 then it is the last permutation (sorted in reverse order)
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }


        // Find a number who is the next smallest larger number
        for(int i=n-1; i>index; i--) {
            if(nums[i] > nums[index]) {
                // Swap both numbers
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                break;
            }
        }

        // Reverse (sort) the rest of the array
        reverse(nums.begin() + index + 1, nums.end());
    }
};