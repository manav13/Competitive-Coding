#include<bits/stdc++.h>
using namespace std;

// Approch 1: Divide approach
vector<int> productExceptSelf(vector<int>& nums) {
    int productOfAll = 1, numOfZeros = 0;
    for(auto num : nums) {
        if(num != 0)
            productOfAll *= num;
        else
            numOfZeros++;
    }
    
    for(int i=0; i<nums.size(); i++) {
        int num = nums[i];
        if(num == 0) {
            if(numOfZeros >= 2)
                nums[i] = 0;
            else
                nums[i] = productOfAll;
        }
        else
            if(numOfZeros > 0)
                nums[i] = 0;
            else
                nums[i] = productOfAll/num;
    }
    return nums;
}

// Approch 2: Prefix and Postfix array approaches
vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> prefix(size), postfix(size), output(size);
    prefix[0] = nums[0];
    postfix[size-1] = nums[size-1];
    
    for(int i=1; i<size; i++) {
        prefix[i] = nums[i]*prefix[i-1];
    }
    
    for(int i=size-2; i>=0; i--) {
        postfix[i] = nums[i]*postfix[i+1];
    }
    
    for(int i=0; i<size; i++) {
        if(i==0)
            output[i] = postfix[i+1];
        else if(i==size-1)
            output[i] = prefix[i-1];
        else
            output[i] = prefix[i-1] * postfix[i+1];
    }
    return output;
}

// Approch 3: Prefix and Postfix with O(1) approach
vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> output(size);    
    output[0] = 1;
    
    // Prefix
    for(int i=1; i<size; i++) {
        output[i] = nums[i-1]*output[i-1];
    }
    
    // Postfix
    int postfix = 1;
    for(int i=size-1; i>=0; i--) {
        output[i] *= postfix;
        postfix *= nums[i];
    }
    return output;
}

int main() {
    return 0;
}