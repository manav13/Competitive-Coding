#include<bits/stdc++.h>
using namespace std;

long maxSumLeftToRight(vector<int> nums) {
    
    vector<long> dupNums;
    for(auto num : nums) {
        dupNums.push_back(num);
    }

    int n = dupNums.size();
    int k = n;
    deque<int> dq{0}; // store index of `nums` elements, elements is in decreasing order, the front is the maximum element.
    for (int i = 1; i < n; ++i) {
        // nums[i] = max(nums[i-k], nums[i-k+1], .., nums[i-1]) + nums[i] = nums[dq.front()] + nums[i]
        dupNums[i] = dupNums[dq.front()] + dupNums[i];

        // Add nums[i] to our deque
        while (!dq.empty() && dupNums[dq.back()] <= dupNums[i]) dq.pop_back(); // Eliminate elements less or equal to nums[i], which will never be chosen in the future
        dq.push_back(i);

        // Remove if the last element is out of window size k
        if (i - dq.front() >= k) dq.pop_front();
    }
    return dupNums[n - 1];
}

int main() {

    vector<int> nums = {10, -20, -5};

    cout << maxSumLeftToRight(nums) << endl;

    return 0;
}