#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> a, vector<int> b, vector<vector<int>> queries) {
    int size = queries.size();
    vector<int> result;
    for(int i=0; i<size; i++) {
        if(queries[i].size() == 2) {
            int count = 0;
            for(auto ax : a) {
                for(auto bx: b) {
                    if(ax + bx == queries[i][1]) count++;
                }
            }
            result.push_back(count);
        }
        else {
            b[queries[i][1]] += queries[i][2];
        }
    }
    return result;
}

int main() {
    int n, m, q;
    vector<int> a(n), b(m);
    cin >> n >> m >> q;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<m; i++) {
        cin >> b[i];
    }
    vector<vector<int>> queries;
    for(int i=0; i<q; i++) {
        int temp;
        if(temp==0) {
            int index, x;
            cin >> index >> x;
            queries.push_back({0, index, x});
        }
        else {
            int x;
            cin >> x;
            queries.push_back({1, x});
        }
    }
    vector<int> result = solution(a,b,queries);
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}