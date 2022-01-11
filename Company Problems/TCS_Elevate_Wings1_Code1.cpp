#include<bits/stdc++.h>
using namespace std;

int main() {
    
    string str;
    string seven = "7";
    string fiftySix = "56";
    string output = "";
    
    cin >> str;

    for (int i=0; i < str.length(); i++) {
        
        string cur = "";
        cur += str[i];

        if (cur == seven) continue;
        if (i+1 <= str.length()) {
            cur += str[i+1];
            if(cur == fiftySix) {
                i++;
                continue;
            }
        }
        output += str[i];
    }
    cout << output << endl;
    return 0;
}