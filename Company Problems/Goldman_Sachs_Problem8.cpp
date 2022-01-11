// Name - Birthday Card Collection
#include<bits/stdc++.h>
using namespace std;

vector<int> hackerCards(vector<int> collection, int d) {
    unordered_set<int> col(collection.begin(), collection.end());
    vector<int> result;
    int sum = 0;
    
    for(int i=1; i<=d; i++) {
        if(col.find(i) != col.end()) continue;
        if(sum+i > d) break;
        sum += i;
        result.push_back(i);
    }
    return result;
}

int main() {
    return 0;
}