// Cisco - Decode Ways

#include<bits/stdc++.h>
using namespace std;

int compute(string decInput) {
    // int p=1, pp=0, n = decInput.size();
    // if(decInput.empty()) return 0;

    // for(int i = n-1; i>=0; i--) {
    //     int cur = decInput[i]=='0'?0:p;
    //     if(i+1<n && (decInput[i]=='1' || (decInput[i] == '2' && decInput[i+1] < '7'))) {
    //         cur += pp;
    //     }
    //     pp = p;
    //     p = cur;
    // }
    // return p;

    vector<int> cost(decInput.size()+2, 0);
    cost[1] = 1;

    for(int i=0; i<decInput.size(); ++i) {
        cost[i+2] = cost[i+1];

        if(i) {
            int twodigit = (decInput[i-1] - '0')*10 + decInput[i] - '0';
            if(twodigit >= 10 && twodigit < 26) cost[i+2] += cost[i];
        }
    }
    return cost.back();
}

int main() {
    string decInput;
    getline(cin, decInput);

    cout << compute(decInput) << endl;

}