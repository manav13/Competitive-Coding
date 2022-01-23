#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    int n = s.size();
    int m = t.size();
    if(m != n) return false;
    
    unordered_map<char, int> hash;
    for(int i=0; i<n; i++) hash[s[i]]++;
    for(int i=0; i<m; i++) hash[t[i]]--;
    
    for(auto num : hash) {
        if(num.second != 0) return false;
    }
    return true;
}

int main() {
    return 0;
}