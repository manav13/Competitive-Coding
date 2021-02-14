#include<bits/stdc++.h>
using namespace std;

int compare (set<char> s1, set<char> s2) {
    int common = 0;

    for (auto itr = s1.begin(); itr!=s1.end(); itr++) {
        for (auto itr2=s2.begin(); itr2!=s2.end(); itr2++) {
            if(*itr == *itr2) {
                ++common;
                continue;
            }
        }
    }
    
    return (s1.size() - common)*(s2.size() - common);
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        map< string, set<char> > dict;
        for(int i=0; i<n; i++) {
            string str;
            cin >> str;
            dict[str.substr(1)].insert(str[0]);
        }

        int result = 0;
        for ( auto itr=dict.begin(); itr!=dict.end(); itr++ ) {
            for (auto itr2=next(itr, 1); itr2!=dict.end(); itr2++) {    
                result += compare(itr->second, itr2->second);
            }
        }
        cout << 2*result << endl;
    }
    return 0;
}