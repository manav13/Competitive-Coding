#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    k = k%size;
    vector<int> lastKElements;
    for(int i=size-k; i<size && i>=0; i++) {
        lastKElements.push_back(nums[i]);
    }
    
    for(int i=size-1; i>=k; i--) {
        nums[i] = nums[i-k];
    }
    for(int i=0; i<k; i++) {
        nums[i] = lastKElements[i];
    }
    return;
}

int main() {
    return 0;
}