// K Smallest Substring

#include<bits/stdc++.h>
using namespace std;

bool checkOnes(string str, int k, int len) {
    int count = 0;
    for(int i=0; i<len; i++) {
        if(str[i] == '1') count++;
        if(count == k) return true;
    }
    return false;
}

bool checkSmallerString(string str, string result, int len) {
    for(int i=0; i<len; i++) {
        if(str[i] != result[i]) {
            if(str[i] == 0) return true;
            else return false;
        }
    }
    return false;
}

string compute(string num, int k) {
    int size = num.size();
    string result = "";
    for(int len = k; len<=size; len++) {
        for(int j=0; j<size-len; j++) {
            string str = num.substr(j, j+len-1);
            if(checkOnes(str, k, len)) {
                if(result == "") result = str;
                else {
                    if(checkSmallerString(str, result, len)) {
                        result = str;
                    }
                }
            }
        }
        if(result != "") break;
    }
    return result;
}

int main() {
    string num;
    int k;
    cin >> k;
    cin >> num;
    cout << compute(num, k) << endl;
    return 0;
}