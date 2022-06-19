#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0], cur = 0;
        for(auto num : nums) {
            cur += num;
            max = max < cur ? cur : max;
            if(cur < 0) cur = 0;
        }
        return max;
    }
};

int main() {
    return 0;
}