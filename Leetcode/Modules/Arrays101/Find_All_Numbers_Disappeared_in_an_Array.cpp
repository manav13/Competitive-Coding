#include<bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    for(int i=0; i<n; i++) {
        if(nums[abs(nums[i])-1] > 0) {
            nums[abs(nums[i])-1] *= -1;
        }
    }
    
    vector<int> result;
    for(int i=0; i<n; i++) {
        if(nums[i] > 0) result.push_back(i+1);
    }
    return result;
}

int main() {
    return 0;
}