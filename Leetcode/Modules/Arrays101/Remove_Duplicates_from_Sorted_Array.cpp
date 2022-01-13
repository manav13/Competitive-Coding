#include<bits/stdc++.h>
using namespace std;

void leftShift(vector<int> &arr, int size, int index1, int index2) {
    for(int i=index1; i<size; i++) {
        arr[i] = arr[index2+i-index1];
    }
}

// int removeDuplicates(vector<int>& nums) {
//     int size = nums.size();
//     if(size == 0) return 0;
//     int curNum = nums[0], startIndex = 0;
    
//     for(int i=1; i<size; i++) {
//         if(nums[i]!=curNum) {
//             curNum = nums[i];
//             int numOfDup = i-1-startIndex;
//             size -= numOfDup;
//             leftShift(nums, size, startIndex+1, i);
//             startIndex++;
//             i = startIndex;
//         }
//     }
//     if(nums[size-1] == nums[startIndex]) size -= size - startIndex - 1;
//     return size;
// }

// Space = O(1) & Time = O(N)
int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    if(size == 0 or size == 1) return size;
    
    int i=0;
    
    for(int j=1; j<size; j++) {
        if(nums[i] != nums[j]) {
            nums[++i] = nums[j];
        }
    }
    nums[++i] = nums[size-1];
    return i;
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

    int k = removeDuplicates(nums);

    for(int i=0; i<k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}