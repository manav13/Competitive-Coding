#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        
        for(auto c : s) {
            hash[c]++;
        }
        for(auto c : t) {
            hash[c]--;
        }
        for(auto key : hash) {
            if(key.second != 0) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}