#include<bits/stdc++.h>
using namespace std;

int findMax(vector<vector<int>> &points, int index, int previousActivity, vector<vector<int>> &dp) {

    if(index < 0)
        return 0;

    if(dp[index][previousActivity] != -1)
        return dp[index][previousActivity];

    vector<int> day = points[index];
    
    int p1 = INT_MIN;
    int p2 = INT_MIN;
    int p3 = INT_MIN;

    if(previousActivity != 1) {
        p1 = day[0] + findMax(points, index-1, 1, dp);
    }
        
    if(previousActivity != 2) {
        p2 = day[1] + findMax(points, index-1, 2, dp);
    }
        
    if(previousActivity != 3) {
        p3 = day[2] + findMax(points, index-1, 3, dp);
    }
    
    int max1 = max(p1, p2);
    dp[index][previousActivity] = max(max1, p3);
    return dp[index][previousActivity];

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return findMax(points, n-1, 0, dp);
}

int main() {
    vector<vector<int>> points = {
        {1,2,5},
        {3,1,1},
        {3,3,3}
    };

    cout << ninjaTraining(points.size(), points) << endl;
}