#include<bits/stdc++.h>
using namespace std;

void printAllSubsequence(vector<int> a, int index, vector<int> ans) {
    // Base Case
    if(index >= a.size()) {
        for(int i=0; i<ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }

    // Consider the element at index
    ans.push_back(a[index]);
    printAllSubsequence(a, index+1, ans);
    
    // Do not consider the element at index
    ans.pop_back();
    printAllSubsequence(a, index+1, ans);

    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    printAllSubsequence(a, 0, ans);
}