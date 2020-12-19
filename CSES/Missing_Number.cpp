#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector <int> v(n);
    for (int i=0; i<n-1; ++i) {
        cin >> m;
        v[m-1] = 1;
    }

    for (int i=0; i<n; ++i) {
        if (v[i] == 0) {
            cout << i+1 << "\n";
            break;
        }
    }
    return 0;
}