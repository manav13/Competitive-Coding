#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC = O(n), SC = O(1)
    int majorityElement(vector<int>& nums) {
        int count = 0, element = nums[0];
        for(auto num : nums) {
            if(num == element) count++;
            else count--;
            
            if(count < 0) {
                element = num;
                count = 1;
            }
        }
        return element;
    }

    // TC = O(n), SC = O(n)
    int majorityElement2(vector<int>& nums) {
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