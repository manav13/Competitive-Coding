#include<bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle) {
    int size = columnTitle.size();
    int output = 0;
    for(int i=size-1; i>=0; i--) {
        int num = columnTitle[i] - 'A' + 1;
        output += (pow(26, size-1-i) * num);
    }
    return output;
}

int main() {
    return 0;
}