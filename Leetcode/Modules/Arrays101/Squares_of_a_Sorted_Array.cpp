#include<bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int size = nums.size();
    int index=size;
    for(int i=0; i<size; i++) {
        if(nums[i] >= 0) {
            index = i;
            break;
        }
    }
    // cout << index << endl;
    int left = index-1, right = index;
    vector<int> result;
    while(left>=0 || right<size) {
        if(left<0) {
            result.push_back(pow(nums[right], 2));
            right++;
        }
        else if(right == size) {
            result.push_back(pow(nums[left], 2));
            left--;
        }
        
        else if(abs(nums[left]) < abs(nums[right])) {
            result.push_back(pow(nums[left], 2));
            left--;
        }
        else {
            result.push_back(pow(nums[right], 2));
            right++;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    vector<int> result = sortedSquares(nums);

    for(int i=0; i<n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}