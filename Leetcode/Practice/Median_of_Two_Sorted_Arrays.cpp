#include<bits/stdc++.h>
using namespace std;

// Brute Force solution - O(m+n)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    int i=0, j=0;
    vector<int> nums;
    while(i<m || j<n) {
        if(j==n || (i!=m && nums1[i] <= nums2[j])) {
            nums.push_back(nums1[i]);
            i++;
        }
        else {
            nums.push_back(nums2[j]);
            j++;
        }
    }
    int size = m+n;
    if(size%2) {
        return double(nums[int(size/2)]);
    }
    else {
        int mid = int(size/2);
        return (double(nums[mid-1] + nums[mid])/2);
    }
}

int main() {
    findMedianSortedArrays({1,2}, {3, 4});
    return 0;
}