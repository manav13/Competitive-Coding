#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int size = nums.size();
    int left = 0, right = size-1;
    int ans = -1;
    while(left <= right) {
        int mid = int((left+right)/2);
        if(nums[mid] == target) {
            ans = mid;
            break;
        }
        else if (target > nums[mid]) {
            left = mid+1;
        }
        else if(target < nums[mid]) {
            right = mid-1;
        }
    }
    return ans;
}

int main() {
    return 0;
}