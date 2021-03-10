#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int t;
    cin >> t;
    while(t) {
        long long int n;
        cin >> n;
        vector<long long int> a(n);
        for(long long int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long int count = 0;
        int flag = 0;
        for(long long int i=0; i<n; i++) {
            if(a[i] < (i+1)) {
                count += (i+1 - a[i]);
            }
            else if (a[i] > (i+1)) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) cout << "Second" << endl;
        else cout << (count%2 == 0 ? "Second" : "First") << endl;
        --t;
    }
    return 0;
}