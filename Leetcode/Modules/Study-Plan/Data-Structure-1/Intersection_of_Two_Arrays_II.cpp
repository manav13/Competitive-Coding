#include<bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    
    unordered_map<int, int> hash1;
    for(int i=0; i<n; i++) {
        hash1[nums1[i]]++;
    }
    vector<int> ans;
    for(int i=0; i<m; i++) {
        if(hash1.find(nums2[i]) != hash1.end() && hash1[nums2[i]] != 0) {
            ans.push_back(nums2[i]);
            hash1[nums2[i]]--;
        }
    }
    return ans;
}

int main() {
    return 0;
}