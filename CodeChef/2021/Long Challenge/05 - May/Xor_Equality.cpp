#include<bits/stdc++.h>
using namespace std;

long long int powerMod(long long int x, long long int y) {
    const unsigned int M = 1000000007;
    long long int ans = 1;
    while (y>0) {
        if(y%2 == 1) {
            ans = (ans*x)%M;
        }
        x = (x*x)%M;
        y = y >> 1;
    }
    return ans;
}

int main() {
    const unsigned int M = 1000000007;
    long long int t;
    cin >> t;
    while(t--) {
        long long int n;
        cin >> n;
        long long int ans = powerMod(2, n-1); //(pow(2, n)-1)/2 + 1;
        cout << ans % M << endl;
    }
    return 0;
}