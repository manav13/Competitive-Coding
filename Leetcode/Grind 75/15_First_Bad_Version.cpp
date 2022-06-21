#include<bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1, high=n;
        int mid = low + (high-low)/2;
        while(mid>0) {
            if(isBadVersion(mid)) {
                if(!isBadVersion(mid-1)) return mid;
                else high = mid-1;
            }
            else {
                if(isBadVersion(mid+1)) return mid+1;
                else low = mid+1;
            }
            mid = low + (high-low)/2;
        }
        return n;
    }
};

int main() {
    return 0;
}