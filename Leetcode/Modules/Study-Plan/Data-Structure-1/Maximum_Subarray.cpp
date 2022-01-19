#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    int maxSum = nums[0], curSum = 0;
    for(int i=0; i<size; i++) {
        curSum += nums[i];
        maxSum = (maxSum < curSum ? curSum : maxSum);
        
        if(curSum<0) curSum = 0;
    }
    return maxSum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << maxSubArray(nums) << endl;
}