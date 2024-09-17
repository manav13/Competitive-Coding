class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Intuition:
        // There are 3 pointers in a hypothetical array: low, mid, high
        // [0...low-1] = 0's
        // [low...mid-1] = 1's
        // [mid...high] = random unsorted 0/1/2
        // [high+1...n-1] = 2's

        // So if nums[mid] == 0 then swap with nums[low] & low++ mid++
        // if nums[mid] == 1 then mid++;
        // if nums[mid] == 2 then swap with nums[high] & high--

        int n = nums.size();
        int low = 0, mid = 0, high = n-1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};