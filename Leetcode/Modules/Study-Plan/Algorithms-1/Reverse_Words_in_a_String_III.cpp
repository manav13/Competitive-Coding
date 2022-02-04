#include<bits/stdc++.h>
using namespace std;

void reverse(string &s, int startIndex, int endIndex) {
    while(startIndex <= endIndex) {
        swap(s[startIndex], s[endIndex]);
        startIndex++;
        endIndex--;
    }
}

string reverseWords(string s) {
    int size = s.size();
    int startIndex=0, endIndex;
    for(int i=0; i<size; i++) {
        if(s[i] == ' ') {
            endIndex = i-1;
            reverse(s, startIndex, endIndex);
            
            startIndex = i+1;
        }
    }
    reverse(s, startIndex, size-1);
    return s;
}

int main() {
    return 0;
}