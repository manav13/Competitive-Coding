#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    int size = nums.size();
    for(int i=0; i<size; i++) {
        
        int numToFind = target - nums[i];
        
        if(hash.find(numToFind) != hash.end()) {
            return {hash[numToFind], i};
        }
        hash[nums[i]] = i;
    }
    return {};
}

int main() {
    return 0;
}