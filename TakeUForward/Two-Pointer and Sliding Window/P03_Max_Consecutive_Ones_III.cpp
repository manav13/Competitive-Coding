class Solution {
public:
    int longestOnes_Better(vector<int>& nums, int k) {
        // View problem as longest substring as at most k zeros
        // TC = O(2N) SC = O(N)
        int size = nums.size();
        int l = 0, r = 0, maxLength = 0, numZeros = 0;

        while(r < size) {
            if(nums[r] == 0) {
                numZeros++;
            }
            if(numZeros >= k) {
                // Move left pointer until numZeros are in range
                while(numZeros > k) {
                    if(nums[l] == 0)
                        numZeros--;
                    l++;
                }
            }

            maxLength = max(maxLength, r-l+1);
            r++;
        }

        return maxLength;
    }

    int longestOnes_Optimal(vector<int>& nums, int k) {
        // TC = O(N) SC = O(N)
        int size = nums.size();
        int l = 0, r = 0, maxLength = 0, numZeros = 0;

        while(r < size) {
            if(nums[r] == 0) {
                numZeros++;
            }
            if(numZeros > k) {
                // Move left pointer until numZeros are in range
                if(nums[l] == 0) {
                    numZeros--;
                }
                l++;
            }

            maxLength = max(maxLength, r-l+1);
            r++;
        }

        return maxLength;
    }
};