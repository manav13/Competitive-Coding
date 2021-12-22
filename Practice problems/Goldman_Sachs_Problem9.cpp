// Name - Grouping Transactions by Items' Name
#include<bits/stdc++.h>
using namespace std;

vector<string> groupTransactions(vector<string> transactions) {
    
    map<string, int> transCount;
    int size = transactions.size();
    
    for(int i=0; i<size; i++) {
        if(transCount.find(transactions[i]) == transCount.end()) {
            transCount[transactions[i]] = 1;
        }
        else {
            transCount[transactions[i]] += 1;
        }
    }
    
    vector<string> result;
    for(auto it : transCount) {
        string ans = it.first + " ";
        ans += to_string(it.second);
        result.push_back(ans);
    }
    return result;

}

int main() {
    return 0;
}