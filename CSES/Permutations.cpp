#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n, m;
    cin >> n;
    if ( n == 1) cout << "1";
    else if ( n<=3 ) cout << "NO SOLUTION";
    else {
        m = 2;
        while (m<=n) {
            cout << m << " ";
            m += 2;
        }
        m = 1;
        while (m<=n) {
            cout << m << " ";
            m += 2;
        }
    }
    return 0;
}