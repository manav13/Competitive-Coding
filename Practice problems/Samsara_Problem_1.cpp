#include<bits/stdc++.h>
using namespace std;

int compute(string s) {
    int size = s.size();
    int count = 0;
    for(int i=0; i<size-2; i++) {
        char a = s[i], b = s[i+1], c = s[i+2];
        if(a!=b && b!=c && c!=a) count++;
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    cout << compute(s) << endl;
    return 0;
}