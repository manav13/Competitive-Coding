#include<bits/stdc++.h>
using namespace std;

int printOneSubsequence(vector<int> a, int index, int sum, int target) {
    // Base condition
    if(index == a.size()) {
        if(sum == target) {
            return 1;
        }
        return 0;
    }

    // Take condition
    sum += a[index];
    int l = printOneSubsequence(a, index+1, sum, target);

    // Do not take condition
    sum -= a[index];
    int r = printOneSubsequence(a, index+1, sum, target);

    return l + r;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << printOneSubsequence(a, 0, 0, target) << endl;
}