#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // <number, index>
        unordered_map<int, int> hash;
        int size = nums.size();
        vector<int> result;
        for(int i=0; i<size; i++) {
            int secondNumber = target - nums[i];
            if(hash.find(secondNumber) != hash.end()) {
                result.push_back(i);
                result.push_back(hash[secondNumber]);
                break;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};

int main() {
    return 0;
}