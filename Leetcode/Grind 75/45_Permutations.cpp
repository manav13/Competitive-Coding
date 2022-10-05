#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void findPermutations(int size, int numSize, vector<int> nums, vector<int>& ds, vector<vector<int>>& output, vector<int>& visited) {
        if(size == numSize) {
            output.push_back(ds);
        }
        
        for(int i=0; i<numSize; i++) {
            if(visited[i] == 0) {
                ds.push_back(nums[i]);
                size++;
                visited[i] = 1;
                
                findPermutations(size, numSize, nums, ds, output, visited);
                
                visited[i] = 0;
                size--;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int numSize = nums.size();
        vector<int> ds;
        vector<int> visited(numSize, 0);
        
        vector<vector<int>> output;
        
        findPermutations(0, numSize, nums, ds, output, visited);
        return output;
    }
};

int main() {
    return 0;
}