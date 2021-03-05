#include<bits/stdc++.h>
using namespace std;

void deleteVal(vector<int>& nums, int index, int len) {
    for(int i=index+1; i<len; i++) {
        nums[i-1] = nums[i];
    }
    return;
}

int removeElement(vector<int>& nums, int val) {
    int len = nums.size();
    for(int i=0; i<len; i++) {
        if(nums[i] == val) {
            deleteVal(nums, i, len);
            --len;
            --i;
        }
    }
    
    // Printing Details
    cout << "Output: " << len << endl;
    cout << "Array: ";
    for(int i=0; i<len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    //
    return len;
}
int main() {
    int n, val;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        nums[i] = temp;
    }
    cin >> val;
    int m = removeElement(nums, val);
    // cout << removeElement(nums, val) << endl;
    // for(auto num : nums) {
    //     cout << num << " ";
    // }
    // cout << endl;
    return 0;
}