#include<bits/stdc++.h>
using namespace std;

void findPermutationsApproach1(vector<int> nums, int size, int index, vector<int>&ds, vector<vector<int>> &output, vector<int>& visited) {
    if(ds.size() == size) {
        output.push_back(ds);
        return;
    }
    
    for(int i=0; i<size; i++) {
        if(visited[i] == 0) {
            ds.push_back(nums[i]);
            visited[i] = 1;
            
            findPermutationsApproach1(nums, size, i, ds, output, visited);
            
            visited[i] = 0;
            ds.pop_back();
        }
    }
    return;
}

void findPermutationsApproach2(vector<int>& nums, int size, int index, vector<vector<int>>& output) {
    if(index == size-1) {
        output.push_back(nums);
        return;
    }
    
    for(int i=index; i<size; i++) {
        swap(nums[i], nums[index]);
        findPermutationsApproach2(nums, size, index+1, output);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> output;
    vector<int> ds;
    int size = nums.size();
    
    vector<int> visited(size, 0);
    // findPermutationsApproach1(nums, size, 0, ds, output, visited);
    findPermutationsApproach2(nums, size, 0, output);
    return output;
}

int main() {
    return 0;
}