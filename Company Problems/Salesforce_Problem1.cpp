#include<bits/stdc++.h>
using namespace std;

vector<int> compute(vector<int> priorities) {
    int size = priorities.size();
    map<int, int> hash;
    vector<int> ans(priorities);
    sort(ans.begin(), ans.end());
    int counter = 1;
    
    for(int i=0; i<size; i++) {
        if(hash.find(ans[i]) == hash.end()) {
            hash.insert({ans[i], counter});
            counter++;
        }
    }

    for(int i=0; i<size; i++) {
        priorities[i] = hash[priorities[i]];
    }
    return priorities;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    while(n--) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    vector<int> ans = compute(arr);

    for(auto it:ans) {
        cout << it << " ";
    }
    cout << endl;
}