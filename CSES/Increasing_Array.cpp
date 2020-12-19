#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int n, cur, prev;
    long long int sum = 0;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> cur;
        if(i == 0) prev = cur;
        if (cur < prev) {
            sum += (prev-cur);
        }
        else {
            prev = cur;
        }
    }
    cout << sum;
    return 0;
}