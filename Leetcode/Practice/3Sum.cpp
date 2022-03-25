#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int size = nums.size();
    if(size<3) return result;
    
    sort(nums.begin(), nums.end());
    for(int i=0; i<size-2; i++) {
        if(i>0 && nums[i-1] == nums[i]) continue;
        int left = i+1, right = size-1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum > 0) right--;
            else if (sum < 0) left++;
            else {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                while(nums[left-1] == nums[left] && left < right) {
                    left++;
                }
            }
        }
    }
    return result;
}

int main() {
    return 0;
}