#include<bits/stdc++.h>
using namespace std;

vector<int> compute(vector<string> queries, int diff) {
    unordered_map<int, int> hash;
    vector<int> ans;
    for(auto query : queries) {
        if(query[0] == '+') {
            hash[stoi(query.substr(1))]++;
        }
        else {
            hash[stoi(query.substr(1))] = 0;
        }
        int pairCount = 0;
        for(auto it : hash) {
            if(hash.find(it.first - diff) != hash.end()) {
                if(hash[it.first - diff] > 0) 
                    pairCount += hash[it.first - diff];
            }
        }
        ans.push_back(pairCount);
    }
    return ans;
}

int main() {  
    int n, diff;
    cin >> n;
    cin >> diff;
    vector<string> queries;

    for(int i=0; i<n; i++) {
        string temp;
        cin >> temp;
        queries.push_back(temp);
    }

    vector<int> ans = compute(queries, diff);
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}