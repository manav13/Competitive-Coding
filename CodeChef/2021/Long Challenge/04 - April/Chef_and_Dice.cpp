#include<bits/stdc++.h>
using namespace std;

long long int ans(long long int n) {
    switch(n) {
        case 1: return 20;
        case 2: return 36;
        case 3: return 51;
        case 4: return 60;
    }
    return 0;
}

int main() {
    long long int t;
    cin >> t;
    while(t) {
        long long int n;
        cin >> n;
        if (n<=4) cout << ans(n) << endl;
        else {
            long long int n_stack = (long long int)(n/4);
            long long int singles = n%4;
            long long int result = (n_stack-1)*44 + singles*11 + ans(singles) + (4-singles)*15;
            cout << result << endl;
        }
        --t;
    }
    return 0;
}