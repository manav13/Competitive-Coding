#include<bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t) {
    string s1 = "", s2 = "";
    for(auto c : s) {
        if(c == '#' && !s1.empty()) s1.pop_back();
        else if(c !='#') s1 += c;
    }
    for(auto c : t) {
        if(c == '#' && !s2.empty()) s2.pop_back();
        else if(c != '#') s2 += c;
    }
    return s1 == s2;
}

int main() {
    return 0;
}