class Solution {
public:
    
    int findNumSubarrays(vector<int>& nums, int k) {
        int l=0, r=0, count = 0;
        unordered_map<int, int> hash;
        int size = nums.size();
        while(r < size) {
            hash[nums[r]]++;

            while(hash.size() > k) {
                hash[nums[l]]--;
                if(hash[nums[l]] == 0)
                    hash.erase(nums[l]);
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findNumSubarrays(nums, k) - findNumSubarrays(nums, k-1);
    }
};