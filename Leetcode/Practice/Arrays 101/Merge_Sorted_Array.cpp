#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> result(m+n);
    int i=0;
    int j=0;
    while( (i+j)<(m+n) ) {
        if(i==m) {
            result[i+j] = nums2[j];
            ++j;
        }
        else if (j==n) {
            result[i+j] = nums1[i];
            ++i;
        }
        else {
            if(nums1[i] <= nums2[j]) {
                result[i+j] = nums1[i];
                ++i;
            }
            else {
                result[i+j] = nums2[j];
                ++j;
            }
        }
    }
    for(int i=0; i<(m+n); i++) {
        nums1[i] = result[i];
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m+n);
    vector<int> nums2(n);

    for (int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        nums1[i] = temp;
    }
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        nums2[i] = temp;
    }
    merge(nums1, m, nums2, n);
    for(int i=0; i<(m+n); i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}