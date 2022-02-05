// Name - Maximum Knowledge
#include<bits/stdc++.h>
using namespace std;

long getMaxKnowledge(int d, vector<int> s, vector<int> e, vector<int> a, int k) {
    int size = s.size();
    vector<vector<int>> meetings;
    for(int i=0; i<size; i++) {
        vector<int> temp;
        temp.push_back(s[i]);
        temp.push_back(e[i]);
        temp.push_back(a[i]);
        meetings.push_back(temp);
    }

    sort(meetings.begin(), meetings.end(), [](auto &p, auto &q) {
        return q[2] < p[2]; 
    });
    vector<pair<int, int>> end;
    vector<int> isStarted(size, 0);
    long maxGain = 0;
    long gain = 0;
    for(int day=1; day<=d; day++) {
        int i=0;
        
        if(end.empty() != true && day == end[0].first) {
            gain -= meetings[end[0].second][2];
            k++;
            isStarted[end[0].second] = 0;
            end.erase(end.begin());
        }
        
        while(k!=0 && i<size) {
            if(meetings[i][0] <= day && meetings[i][1] >= day && isStarted[i]==0) {
                gain += meetings[i][2];
                if(gain > maxGain) maxGain = gain;
                
                isStarted[i] = 1;
                end.push_back({meetings[i][1], i});
                sort(end.begin(), end.end());
                k--; 
            }
            i++;
        }
    }
    return maxGain;
}

int main() {
    cout << getMaxKnowledge(1, {2,5,4,3}, {8,9,7,5}, {800, 1600, 200, 400}, 2) << endl;
}