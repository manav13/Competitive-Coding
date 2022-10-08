#include<bits/stdc++.h>
using namespace std;

static bool sortByStartTime(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

bool isOverlap(vector<int> prev, vector<int> cur) {
    return prev[0] <= cur[0] && cur[0] <= prev[1];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Sort using the start time
    sort(intervals.begin(), intervals.end(), sortByStartTime);
    
    // Iterate through the intervals
    vector<int> prev = intervals[0];
    vector<vector<int>> result;
    for(auto cur : intervals) {
        if(isOverlap(prev, cur)) {
            prev[0] = min(prev[0], cur[0]);
            prev[1] = max(prev[1], cur[1]);
        }
        else {
            result.push_back(prev);
            prev = cur;
        }
    }
    result.push_back(prev);
    return result;
}

int main() {
    vector<vector<int>> intervals = {
        {1, 3}, {8, 10}, {15, 18}, {2, 6}
    };
    vector<vector<int>> results = merge(intervals);
}