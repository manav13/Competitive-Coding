#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int count = 1;
    int max_count = 1;
    cin >> str;
    char c = str[0];
    for (int i=1; i<str.size(); ++i) {
        if (c == str[i]) {
            ++count;
            if (max_count < count) {
                max_count = count;
            }
        }
        else {
            count = 1;
        }
        c = str[i];
    }
    cout << max_count;
    return 0;
}