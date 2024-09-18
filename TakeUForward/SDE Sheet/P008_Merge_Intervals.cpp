class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<int> cur = intervals[0];
        vector<vector<int>> result;

        for(auto interval : intervals) {
            // If they overlap then combine
            if(interval[0] <= cur[1]) {
                cur[0] = min(cur[0], interval[0]);
                cur[1] = max(cur[1], interval[1]);
            }
            else {
                result.push_back(cur);
                cur = interval;
            }
        }
        result.push_back(cur);
        return result;
    }
};