#include<bits/stdc++.h>
using namespace std;

int thirdMax(vector<int>& nums) {
    int size = nums.size();
    if(size == 1) return nums[0];
    if(size == 2) return (nums[0] < nums[1] ? nums[1] : nums[0]);
    
    int max1 = nums[0], max2, max3;
    
    //Assign max2
    int i;
    for(i=1; i<size; i++) {
        if(nums[i]!=max1) {
            if(nums[i]>max1) {
                max2 = max1;
                max1 = nums[i];
            }
            else max2 = nums[i];
            
            break;
        }
    }
    if(i==size) return max1;
    
    //Assign max3
    for(; i<size; i++) {
        if(nums[i]!=max1 && nums[i]!=max2) {
            if(nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if (nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            }
            else max3 = nums[i];
            break;
        }
    }
    if(i==size) return max1;
    
    for(; i<size; i++) {
        if(nums[i] > max3 && nums[i]!=max1 && nums[i]!=max2) {
            max3 = nums[i];
            if(max3 > max2) {
                swap(max2, max3);
                if(max2 > max1) {
                    swap(max1, max2);
                }
            }
        }
    }
    return max3;
}

int main() {
    return 0;
}