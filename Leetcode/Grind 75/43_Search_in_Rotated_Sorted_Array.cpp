#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int size = nums.size();
    int left = 0, right = size-1;
    
    while(left <= right) {
        int mid = left + (right - left)/2;
        
        if(target == nums[mid])
            return mid;
        
        // Mid is in left sorted portion
        if(nums[left] <= nums[mid]) {
            if(target > nums[mid]) {
                left = mid+1;
            }
            else {
                if(target >= nums[left]) {
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            }
        }
        // Right sorted portion
        else {
            if(target < nums[mid]) {
                right = mid-1;
            }
            else {
                if(target <= nums[right]) {
                    left = mid+1;
                }
                else {
                    right = mid-1;
                }
            }
        }
    }
    
    return -1;
}

int main() {
    vector<int> nums = {3, 1};
    int target = 1;
    cout << search(nums, target) << endl;
    return 0;
}