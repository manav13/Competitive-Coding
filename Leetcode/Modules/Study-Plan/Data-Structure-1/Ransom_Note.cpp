#include<bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int m = ransomNote.size();
    int n = magazine.size();
    if(m>n) return false;
    unordered_map<char, int> hash1;
    unordered_map<char, int> hash2;
    for(int i=0; i<m; i++) hash1[ransomNote[i]]++;
    for(int i=0; i<n; i++) hash2[magazine[i]]++;
    
    for(auto ele : hash1) {
        if(ele.second > hash2[ele.first]) return false;
    }
    return true;
}

int main() {
    return 0;
}