#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int size = numbers.size();
    vector<int> ans(2);
    for(int i=0; i<size; i++) {
        if(binary_search(numbers.begin()+i+1, numbers.end(), target-numbers[i])) {
            int index = lower_bound(numbers.begin()+i+1, numbers.end(), target-numbers[i]) - numbers.begin();
            ans[0] = i+1;
            ans[1] = index+1;
            break;
        }
    }
    return ans;
}

int main() {
    return 0;
}