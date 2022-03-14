#include<bits/stdc++.h>
using namespace std;

bool checkHash(unordered_map<char, int> hash1, unordered_map<char, int> hash2) {
    for(auto it : hash1) {
        if(hash2[it.first] != it.second) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int size1 = s1.size(), size2 = s2.size();
    if(size1 > size2) return false;
    
    unordered_map<char, int> hash1, hash2;
    for(int i=0; i<size1; i++) {
        hash1[s1[i]]++;
        hash2[s2[i]]++;
    }
    if(checkHash(hash1, hash2)) return true;
    
    for(int i=1; i<=size2-size1; i++) {
        hash2[s2[i-1]]--;
        hash2[s2[i+size1-1]]++;
        if(checkHash(hash1, hash2)) return true;
    }
    return false;
}}

int main() {
    cout << checkInclusion("abcdxabcde", "abcdeabcdx") << endl;
    return 0;
}