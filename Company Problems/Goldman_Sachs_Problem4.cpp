// Goldman Sachs - Competitive Gaming
#include<bits/stdc++.h>
using namespace std;

bool sortByVal(const pair<int, int> &a, 
               const pair<int, int> &b) { 
    return (a.first > b.first);
}

int compute(int k, int n, vector<int> scores) {
    map<int, int> hash;
    for(int i=0; i<n; i++) {
        if(hash.find(scores[i]) == hash.end()) {
            hash.insert({scores[i], 1});
        }
        else {
            hash[scores[i]] += 1;
        }
    }
    vector<pair <int,int> > vec;

    for(auto it: hash) {
        vec.push_back({it.first, it.second});
    }

    sort(vec.begin(), vec.end(), sortByVal);
    
    int ans = 0;
    for(auto it : vec) {
        if(it.first == 0) break;
        if(k>0) {
            ans += it.second;
            k -= it.second;
        }
    }

    return ans;
}

int main() {
    int k, n; 
    vector<int> scores;
    cin >> k >> n;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        scores.push_back(temp);
    }
    int t = compute(k,n,scores);
    cout << t << endl;
    return 0;
}