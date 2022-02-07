#include<bits/stdc++.h>
using namespace std;

char findTheDifference(string s, string t) {
    unordered_map<char, int> hash;
    for(auto c : s) {
        hash[c]++;
    }
    for(auto c : t) {
        hash[c]--;
    }
    char ans;
    for(auto p : hash) {
        if(p.second != 0) {
            ans = p.first;
            break;
        }
    }
    return ans;
}

int main() {
    return 0;
}