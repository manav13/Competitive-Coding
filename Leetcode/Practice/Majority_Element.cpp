#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> hash;
    
    int size = nums.size();
    int ans = 0;
    for(auto it : nums) {
        hash[it]++;
        if(hash[it] > (size/2)){
            ans = it;
            break;
        }
    }
    return ans;
}

int main() {
    return 0;
}