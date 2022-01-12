#include<bits/stdc++.h>
using namespace std;

void leftShift(vector<int> &arr, int size, int index) {
    for(int i=index+1; i<size; i++) {
        arr[i-1] = arr[i];
    }
}

int removeElement(vector<int>& nums, int val) {
    int size = nums.size();
    
    for(int i=0; i<size; i++) {
        if(nums[i] == val) {
            leftShift(nums, size, i);
            size--;
            i--;
        }
    }
}

int main() {
    return 0;
}