#include<bits/stdc++.h>
using namespace std;

bool isBadVersion(long long int n) {
    return true;
}

int firstBadVersion(int n) {
    // if(n==1) return 1;
    long long int left = 1, right = n;
    while(left <= right) {
        long long int mid = (left+right)/2;
        if(isBadVersion(mid)) {
            if(isBadVersion(mid-1)) {
                right = mid-1;
            }
            else return mid;
        }
        else {
            if(isBadVersion(mid+1)) {
                return mid+1;
            }
            else left = mid+1;
        }
    }
    return -1;
}

int main() {
    return 0;
}