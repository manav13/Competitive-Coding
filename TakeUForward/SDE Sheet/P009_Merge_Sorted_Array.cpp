class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i=0; i<n; i++) {
            nums1[m+i] = nums2[i];
        }
        
        // shell sort

        int len = m+n;
        int gap = len/2 + len%2;
        bool notSeenOne = true;
        while(notSeenOne || gap > 1) {
            if(gap == 1) {
                notSeenOne = false;
            }
            int left = 0;
            int right = left + gap;
            while(right < len) {
                if(nums1[left] > nums1[right]) {
                    swap(nums1[left], nums1[right]);
                }
                left++;
                right++;
            }
            int mod = gap%2;
            gap = gap/2 + mod;
        }
    }
};