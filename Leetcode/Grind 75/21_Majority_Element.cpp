#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        size = size/2;
        unordered_map<int, int> hash;
        for(auto num : nums) {
            hash[num]++;
            if(hash[num] > size) return num;
        }
        return nums[0];
    }
};

int main() {
    return 0;
}