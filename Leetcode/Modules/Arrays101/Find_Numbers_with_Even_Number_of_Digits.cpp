#include<bits/stdc++.h>
using namespace std;

int checkNumOfDigits(int num) {
    int count = 0;
    while(num!=0) {
        count++;
        num = (int) (num/10);
    }
    return count;
}

int findNumbers(vector<int>& nums) {
    
    int size = nums.size();
    int result = 0;
    
    for(auto num : nums) {
        if(checkNumOfDigits(num)%2 == 0) result++;
    }
    
    return result;
}

int main() {
    return 0;
}