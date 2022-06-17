#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1, low = 0;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(target == nums[mid]) return mid;
            else if (target < nums[mid]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}