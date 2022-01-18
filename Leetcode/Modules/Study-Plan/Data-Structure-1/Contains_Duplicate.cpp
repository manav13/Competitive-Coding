#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    int size = nums.size();
    // unordered_map<int, int> numCount;

    // for(int i=0; i<size; i++) {
    //     if(numCount.find(nums[i]) == numCount.end()) numCount[nums[i]]++;
    //     else return true;
    // }
    // return false;
    
    sort(nums.begin(), nums.end());
    for(int i=0; i<size-1; i++) {
        if(nums[i] == nums[i+1]) return true;
    }
    return false;
}

int main() {
    return 0;
}