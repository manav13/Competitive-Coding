#include<bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2) {
    vector<int> ver1, ver2;
    string num = "";
    for(auto ch : version1) {
        if(ch == '.') {
            ver1.push_back(stoi(num));
            num = "";
        }
        else {
            num += ch;
        }
    }
    ver1.push_back(stoi(num));
    num = "";
    for(auto ch : version2) {
        if(ch == '.') {
            ver2.push_back(stoi(num));
            num = "";
        }
        else {
            num += ch;
        }
    }
    ver2.push_back(stoi(num));
    int size1 = ver1.size(), size2 = ver2.size();
    int minSize = min(size1, size2);
    int maxSize = max(size1, size2);
    int ans = 0, i = 0;
    while(i < minSize) {
        if(ver1[i] > ver2[i]) {
            ans = 1;
            return ans;
        }
        else if (ver1[i] < ver2[i]) {
            ans = -1;
            return ans;
        }
        i++;
    }
    bool v = size1 < size2;
    while(i < maxSize) {
        if(v && ver2[i] != 0) {
            ans = -1;
            return ans;
        }
        if(!v && ver1[i] != 0) {
            ans = 1;
            return ans;
        }
        i++;
    }
    return ans;
}

int main() {
    return 0;
}