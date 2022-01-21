#include<bits/stdc++.h>
using namespace std;

int maximumDifference(vector<int>& nums) {
    int size = nums.size();
    int maxDiff = 0, curDiff = 0;
    for(int i=1; i<size; i++) {
        curDiff += (nums[i] - nums[i-1]);
        if(maxDiff < curDiff) maxDiff = curDiff;
        if(curDiff < 0) curDiff = 0;
    }
    if(maxDiff == 0 && curDiff == 0) return -1;
    return maxDiff;
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
    cout << maximumDifference(nums) << endl;
}