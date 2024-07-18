#include<bits/stdc++.h>
using namespace std;

int fib_recursion(int n) {
    if(n <= 1)
        return n;

    return fib_recursion(n-1) + fib_recursion(n-2);
}

int fib_memoization(int n, vector<int> &dp) {
    if(n <= 1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = fib_memoization(n-1, dp) + fib_memoization(n-2, dp);
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    // Recursion Solution
    int ans;
    ans = fib_recursion(n);
    cout << "Recursion ans: " << ans << endl;

    // Memoization Solution (Top-down approach)
    vector<int> dp(n+1, -1);
    ans = fib_memoization(n, dp);
    cout << "Memoization ans: " << ans << endl;

    // Tabulation with array solution
    vector<int> dp2(n+1, -1);
    dp2[0] = 0;
    dp2[1] = 1;
    for(int i=2; i<=n; i++) {
        dp2[i] = dp2[i-1] + dp2[i-2];
    }
    cout << "Tabulation with array ans: " << dp2[n] << endl;

    // Tabulation without array solution
    int prev2 = 0;
    int prev = 1;
    for(int i=2; i<=n; i++) {
        int curVal = prev + prev2;
        prev2 = prev;
        prev = curVal;
    }
    cout << "Tabulation without array ans: " << prev << endl;


}