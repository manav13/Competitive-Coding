// Question: Task Scheduling
// TC = 10/15 

#include<bits/stdc++.h>
using namespace std;

bool sortBy(const pair<int,int> &a, const pair<int,int> &b)
{
    return (static_cast<double>(a.first)/a.second) > (static_cast<double>(b.first)/b.second);
}

int solution(vector<int> cost, vector<int> time) {
    int n = cost.size();
    vector<pair<int, int>> timeByCost;

    for(int i=0; i<n; i++) {
        timeByCost.push_back({time[i], cost[i]});
    }

    sort(timeByCost.begin(), timeByCost.end(), sortBy);

    int numTask = n, i=0, minCost = 0;
    while(numTask>0) {
        minCost += timeByCost[i].second;
        numTask -= (timeByCost[i].first+1);
        i++;
    }
    return minCost;
}

int main() {

    vector<int> cost = {2,3,4,2};
    vector<int> time = {1,1,1,1};

    cout << solution(cost, time) << endl;

    return 0;
}