#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int size = nums.size();
    int max = 0, result = 0;

    for(auto num : nums) {
        if(num == 1) max++;
        else {
            if(result < max) {
                result = max;
            }
            max = 0;
        }
    }
    
    return (result < max ? max : result);
}

int main() {
    return 0;
}