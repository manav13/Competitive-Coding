#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(auto num : nums) {
            if(hash.find(num) != hash.end()) return true;
            hash[num]++;
        }
        return false;
    }
};

int main() {
    return 0;
}