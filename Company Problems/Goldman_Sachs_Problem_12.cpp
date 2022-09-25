// Question: Lottery Coupons
#include<bits/stdc++.h>
using namespace std;

int lotteryCoupons(int n) {
    unordered_map<int, int> counts;
    for(int i=1; i<=n; i++) {
        int s = 0;
        int num = i;
        while(num) {
            s += num%10;
            num = (int)num/10;
        }
        counts[s]++;
    }
    int winners = 0;
    for(auto it : counts) {
        winners = max(winners, it.second);
    }
    int ans = 0;
    for(auto it : counts) {
        if(it.second == winners) {
            ans++;
        }
    }
    return ans;
}

int main() {
    return 0;
}