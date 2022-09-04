#include<bits/stdc++.h>
using namespace std;

class myComparator {
    
    public:
    
    bool operator() (pair<int, int> const &a, pair<int, int> const &b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(auto num : nums) {
            hash[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparator> maxHeap;
        
        for(auto it : hash) {
            maxHeap.push({it.first, it.second});
        }
        vector<int> answer;
        while(k--) {
            answer.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return answer;
    }
};

int main() {
    return 0;
}