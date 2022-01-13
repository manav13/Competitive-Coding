#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int size = nums.size();
    if(size == 1) return;
    
    int i=0;
    while(i<size) {
        if(nums[i] == 0) break;
        else i++;
    }
    if(i==size) return;
    
    for(int j=i+1; j<size; j++) {
        if(nums[j] != 0) {
            nums[i] = nums[j];
            nums[j] = 0;
            i++;
        }
    }
}

int main() {
    return 0;
}