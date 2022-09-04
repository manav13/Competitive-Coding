#include<bits/stdc++.h>
using namespace std;

class myComparator {
    public:
    
    bool operator() (int const &a, int const &b) {
        return a < b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, myComparator> maxHeap;
        
        for(auto num : nums) {
            maxHeap.push(num);
        }
        int answer;
        while(k--) {
            answer = maxHeap.top();
            maxHeap.pop();
        }
        return answer;
    }
};

int main() {
    return 0;
}