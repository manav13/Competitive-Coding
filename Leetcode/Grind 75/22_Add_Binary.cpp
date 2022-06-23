#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    int aSize = a.size(), bSize = b.size();
    bool isALarger = aSize > bSize;
    
    if(isALarger) {
        for(int i=0; i<aSize-bSize; i++) {
            b = '0' + b;
        }
    }
    else {
        for(int i=0; i<bSize-aSize; i++) {
            a = '0' + a;
        }
    }
    
    int size = isALarger ? aSize : bSize;
    int carry = 0;
    string ans = "";
    for(int i=size-1; i>=0; i--) {
        if(a[i] == '1' && b[i] == '1') {
            if(carry == 1) {
                carry = 1;
                ans = '1' + ans;
            }
            else {
                carry = 1;
                ans = '0' + ans;
            }
        }
        else if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) {
            if(carry == 1) {
                ans = '0' + ans;
            }
            else {
                ans = '1' + ans;
            }
        }
        else {
            if(carry == 1) {
                carry = 0;
                ans = '1' + ans;
            }
            else {
                ans = '0' + ans;
            }
        }
    }
    if(carry == 1) ans = '1' + ans;
    return ans;
}

int main() {
    cout << addBinary("1", "111") << endl;
    return 0;
}