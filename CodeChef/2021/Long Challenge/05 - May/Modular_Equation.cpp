#include<bits/stdc++.h>
using namespace std;

int main() {
    // int a, b;
    // cin >> a >> b;
    // cout << (a%b) << endl;
    int t;
    cin >> t;
    while(t--) {
        int n, m, a, b, result;
        cin >> n >> m;
        result = n-1;
        for(a=2; a<n; a++) {
            // if(a>=m) {
            //     result += (n-a);
            //     continue;
            // }
            for(b=a+1; b<=n; b++) {
                if(((m%a)%b) == ((m%b)%a)) {
                    ++result;
                    cout << "(" << a << ", " << b << ") ";
                }
            }
            cout << endl;
        }
        cout << result << endl;
    }
}