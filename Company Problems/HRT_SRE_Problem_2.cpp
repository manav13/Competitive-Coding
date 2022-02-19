#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &arr) {
    // create an empty map
    unordered_map<int, vector<int> > map;
  
    // create an empty vector of pairs to store
    // subarray starting and ending index
    vector <pair<int, int>> out;
    int n = arr.size();
    // Maintains sum of elements so far
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // add current element to sum
        sum += arr[i];
  
        // if sum is 0, we found a subarray starting
        // from index 0 and ending at index i
        if (sum == 0)
            count++;
            // out.push_back(make_pair(0, i));

  
        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if (map.find(sum) != map.end())
        {
            // map[sum] stores starting index of all subarrays
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                // out.push_back(make_pair(*it + 1, i));
                count++;
        }
        if(count > 1000000000) return -1;
        // Important - no else
        map[sum].push_back(i);
    }
  
    // return output vector
    return count;
}

int main() {
    return 0;
}