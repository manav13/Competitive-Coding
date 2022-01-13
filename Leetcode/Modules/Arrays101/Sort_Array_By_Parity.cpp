#include<bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int size = nums.size();
    if(size==1) return nums;
    
    int odd = 0;
    while(odd<size) {
        if(nums[odd]%2!=0) break;
        odd++;
    }
    if(odd==size) return nums;
    
    for(int even=odd+1; even<size; even++) {
        if(nums[even]%2==0) {
            swap(nums[odd], nums[even]);
            odd++;
        }
    }
    return nums;
}

int main() {
    return 0;
}