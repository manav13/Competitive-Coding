#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto num : nums) {
            sum += num;
        }
        int actualSum = (n*(n+1))/2;
        return actualSum - sum;
    }
};

int main() {
    return 0;
}