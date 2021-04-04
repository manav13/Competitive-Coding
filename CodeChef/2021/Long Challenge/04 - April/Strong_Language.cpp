#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t) {
        int n,k,count=0;
        cin >> n >> k;
        string s;
        char star = '*';
        int flag = 0;
        cin >> s;
        for(int i=0; i<n; ++i) {
            if(s[i] == star) {
                ++count;
                if(count == k) {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
            }
            else count = 0;
        }
        if(flag==0) cout << "NO" << endl;
        --t;
    }
    return 0;
}