#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int size = nums.size();
        
        for(int i=0; i<size; i++) {
            nums[abs(nums[i])-1] = -1 * abs(nums[abs(nums[i])-1]);
        }
        
        for(int i=0; i<size; i++) {
            if(nums[i] > 0) result.push_back(i+1);
        }
        return result;
    }
};

int main() {
    return 0;
}