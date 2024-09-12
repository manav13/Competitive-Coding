// Problem: Compression techniques

#include<bits/stdc++.h>
using namespace std;

string compressedString(string message) {

    string compString = "";
    
    int len = message.size();
    
    for (int i = 0; i < len; i++) {
        char c = message[i];
        int count = 1;
        
        while (i + 1 < len && message[i + 1] == c) {
            count++;
            i++;
        }

        compString += c;
        
        if (count > 1) {
            compString += to_string(count);
        }
    }
    return compString
};