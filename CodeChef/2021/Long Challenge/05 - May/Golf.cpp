#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long int n, x, k;
        cin >> n >> x >> k;
        cout << ((x%k == 0 || (n+1)%k == x%k) ? "YES" : "NO") << endl;
    }
    return 0;
}