#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x,a,b;
        cin >> x >> a >> b;
        int ans = (a + (100 - x)*b)*10;
        cout << ans << endl;
    }
    return 0;
}