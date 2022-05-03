#include<bits/stdc++.h>
using namespace std;

// O(nlogn) solution
int findUnsortedSubarray(vector<int>& nums) {
    vector<int> dupNums = nums;
    sort(nums.begin(), nums.end());
    
    int size = nums.size();
    int left = 0, right = size-1, ans = 0;

    while(left < size && nums[left] == dupNums[left])
        left++;
    while(right > 0 && nums[right] == dupNums[right])
        right--;
    if(right < left) return ans;
    ans = right - left + 1;
    return ans;
}

int main() {
    return 0;
}