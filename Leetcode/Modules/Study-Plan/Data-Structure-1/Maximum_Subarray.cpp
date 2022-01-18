#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    int maxSum = 0, curSum = 0;
    for(int i=0; i<size; i++) {
        if(curSum + nums[i] < 0) {
            maxSum = (maxSum > curSum ? maxSum : curSum);
            curSum = 0;
        }
        else curSum += nums[i];
    }
    return (maxSum > curSum ? maxSum : curSum);
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