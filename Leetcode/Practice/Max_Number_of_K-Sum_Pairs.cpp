#include<bits/stdc++.h>
using namespace std;

// Using Hash-map, Time = O(n)
int maxOperations(vector<int>& nums, int k) {   
    unordered_map<int, int> hash;
    for(auto num : nums) {
        hash[num]++;
    }
    int count = 0;
    for(auto it : hash) {
        int n1 = it.first, n2 = k - it.first;
        
        if(hash[n1]>0 && hash.find(n2) != hash.end() && hash[n2]>0) {
            int minCount = min(hash[n1], hash[n2]);
            if(n1 == n2)
                minCount /= 2;
            count += minCount;
            hash[n1]-= minCount;
            hash[n2]-= minCount;
        }
    }
    return count;
}


// Using sorting, Time = O(nlogn)
int maxOperations(vector<int>& nums, int k) {   
    sort(nums.begin(), nums.end());
    int p1 = 0, p2 = nums.size()-1;
    int count = 0;
    while(p1<p2) {
        if(nums[p1] + nums[p2] == k) {
            count++;
            p1++;
            p2--;
        }
        else if (nums[p1] + nums[p2] > k) {
            p2--;
        }
        else {
            p1++;
        }
    }
    return count;
}

int main() {
    return 0;
}