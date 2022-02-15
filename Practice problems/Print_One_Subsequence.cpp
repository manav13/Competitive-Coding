#include<bits/stdc++.h>
using namespace std;

bool printOneSubsequence(vector<int> a, int index, vector<int> ans, int sum, int target) {
    // Base condition
    if(index == a.size()) {
        if(sum == target) {
            for(auto it: ans) {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    // Take condition
    ans.push_back(a[index]);
    sum += a[index];
    if(printOneSubsequence(a, index+1, ans, sum, target)) return true;

    // Do not take condition
    ans.pop_back();
    sum -= a[index];
    if(printOneSubsequence(a, index+1, ans, sum, target)) return true;

    return false;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    bool p = printOneSubsequence(a, 0, ans, 0, target);
}