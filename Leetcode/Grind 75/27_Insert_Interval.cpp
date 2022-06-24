#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    
    for(auto interval : intervals) {
        if(interval[1] < newInterval[0]) {
            result.push_back(interval);
        }
        else if(newInterval[1] < interval[0]) {
            result.push_back(newInterval);
            newInterval = interval;
        }
        else {
            newInterval[0] = min(interval[0], newInterval[0]);
            newInterval[1] = max(interval[1], newInterval[1]);
        }
    }
    result.push_back(newInterval);
    return result;
}

int main() {

    vector<vector<int>> intervals = {
        {1,2},
        {3,5},
        {6,7},
        {8,10},
        {12,16},
        {17, 19}
    };
    vector<int> newInterval = {4, 8};
    insert(intervals, newInterval);

    return 0;
}