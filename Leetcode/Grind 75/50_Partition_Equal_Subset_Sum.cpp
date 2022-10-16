#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int size = nums.size();
    int target = 0;
    for(auto num : nums) {
        target += num;
    }
    if(target%2 == 1)
        return false;
    target /= 2;
    
    unordered_set<int> dp;
    dp.insert(0);
    
    for(int i=size-1; i>=0; i--) {
        
        unordered_set<int> nextDp;
        
        for(auto itr : dp) {
            int newEle = nums[i] + itr;
            if(newEle == target)
                return true;
            nextDp.insert(itr);
            nextDp.insert(newEle);
        }
        
        dp = nextDp;
        
    }
    
    return false;
}

int main() {
    vector<int> nums = {14,9,8,4,3,2};
    cout << canPartition(nums) << endl;
}