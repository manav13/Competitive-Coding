#include<bits/stdc++.h>
using namespace std;

bool compareHashMaps(unordered_map<char, int> sHash, unordered_map<char, int> pHash) {
    for(auto c : pHash) {
        if(c.second != sHash[c.first]) return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    int pSize = p.size(), sSize = s.size();
    if(pSize > sSize) return {};
    
    unordered_map<char, int> pHash, sHash;
    for(int i=0; i<pSize; i++) pHash[p[i]]++;
    
    vector<int> ans;
    int right = pSize-1;
    for(int i=0; i<=right; i++) sHash[s[i]]++;
    
    for(int left = 0; left < sSize-pSize+1; left++) {
        if(compareHashMaps(sHash, pHash)) ans.push_back(left);
        
        sHash[s[left]]--;
        right++;
        sHash[s[right]]++;
    }
    return ans;
}

int main() {
    return 0;
}