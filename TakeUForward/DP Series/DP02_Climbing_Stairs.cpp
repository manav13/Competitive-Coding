#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    // It is a Fibonacci problem
    int prev2 = 1;
    int prev = 1;

    for(int i=2; i<=n; i++) {
        int curVal = prev + prev2;
        prev2 = prev;
        prev = curVal;
    }

    return prev;
}

int main() {
    int n;
    cin >> n;

    cout << climbStairs(n) << endl;
}