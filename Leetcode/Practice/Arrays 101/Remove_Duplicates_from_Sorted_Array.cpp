#include<bits/stdc++.h>
using namespace std;

void deleteVal(vector<int>& nums, int index, int len) {
    for(int i=index+1; i<len; i++) {
        nums[i-1] = nums[i];
    }
    return;
}

int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    for(int i=1; i<len; i++) {
        if(nums[i-1] == nums[i]) {
            deleteVal(nums, i, len);
            --len;
            --i;
        }
    }
    return len;
}

int main() {
    return 0;
}