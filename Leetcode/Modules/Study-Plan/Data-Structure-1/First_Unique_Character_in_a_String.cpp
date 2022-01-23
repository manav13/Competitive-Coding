#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> hash;
    int size = s.size();
    for(int i=0; i<size; i++) {
        hash[s[i]]++;
    }
    for(int i=0; i<size; i++) {
        if(hash[s[i]] == 1) return i;
    }
    return -1;
}

int main() {
    string s;
    cin >> s;
    cout << firstUniqChar(s) << endl;
    return 0;
}