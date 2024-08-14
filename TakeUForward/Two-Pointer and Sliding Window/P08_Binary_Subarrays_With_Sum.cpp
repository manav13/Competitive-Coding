class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Same as problem: Subarray Sum Equals K

        int size = nums.size();
        int count = 0;
        // <sum, freq>
        unordered_map<int, int> hash;
        int sum = 0;
        hash[sum]++;

        for(int i=0; i<size; i++) {
            sum += nums[i];
            int prefix = sum-goal;
            if(hash.find(prefix) != hash.end()) {
                count += hash[prefix];
            }
            hash[sum]++;
        }

        return count;
    }
};