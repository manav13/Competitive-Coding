#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int start = 0, end = 0, maxLen = 0;
    for(int i=0; i<s.size(); i++) {
        if(hash.find(s[i]) == hash.end()) {
            hash[s[i]] = i;
            end = i;
        }
        else {
            start = max(start, hash[s[i]]+1);
            hash[s[i]] = i;
            end = i;
        }
        maxLen = max(maxLen, end-start+1);
    }
    return maxLen;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}