#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash1, hash2;
        for(auto c : ransomNote) {
            hash1[c]++;
        }
        for(auto c : magazine) {
            hash2[c]++;
        }
        
        for(auto t : hash1) {
            if(hash2.find(t.first) == hash2.end() || t.second > hash2[t.first]) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}