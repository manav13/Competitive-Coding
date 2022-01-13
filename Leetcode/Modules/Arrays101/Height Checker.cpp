#include<bits/stdc++.h>
using namespace std;

int heightChecker(vector<int>& heights) {
    int size = heights.size();
    vector<int> nums(heights);
    sort(nums.begin(), nums.end());
    int count = 0;
    for(int i=0; i<size; i++) {
        if(heights[i]!=nums[i]) count++;
    }
    return count;
}

int main() {
    return 0;
}