#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int k;
        long long int sum = 0;
        cin >> k;
        for(int i=1; i<=2*k; i++) {
            sum += gcd(k + (i*i), k + (i+1)*(i+1));
        }
        cout << sum << endl;
    }
    return 0;
}