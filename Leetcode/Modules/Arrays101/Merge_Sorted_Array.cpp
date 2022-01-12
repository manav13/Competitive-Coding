#include<bits/stdc++.h>
using namespace std;

void rightShift(vector<int> &arr, int size, int index, int value) {
    for(int i=size-2; i>=index; i--) {
        arr[i+1] = arr[i];
    }
    arr[index] = value;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int size = m+n;
    int i=0, j=0;
    while(m>0 && n>0) {
        if(nums2[j] < nums1[i]) {
            rightShift(nums1, size, i, nums2[j]);
            j++;
            n--;
            m++;
        }
        i++;
        m--;
    }
    if(m==0) {
        while(i<size) {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
    }
}

int main() {
    return 0;
}