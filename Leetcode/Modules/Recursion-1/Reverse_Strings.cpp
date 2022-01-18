#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
    int size = s.size();
    int i = 0, j = size-1;
    while(i<j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

int main() {
    return 0;
}