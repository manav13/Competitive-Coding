#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int size = s.size();
    if(size == 0 || size == 1) return size;
    
    int max = 1, left = 0, right = 1;
    // char, index
    unordered_map<char, int> hash;
    hash[s[0]] = 0;
    for(right = 1; right<size; right++) {
        if(hash.find(s[right]) != hash.end() && left <= hash[s[right]]) {
            left = hash[s[right]] + 1;
        }
        hash[s[right]] = right;
        if(max < right-left+1) max = right-left+1;
    }
    return max;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}