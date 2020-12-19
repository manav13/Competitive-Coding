#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(char str[]) {
    // Base Case
    if (str[0] == '\0') {
        return;
    }
    
    // Handle first character and then call recusion
    if (str[0] != str[1]) {
        removeDuplicates(str+1);
    } else {
        int i=1;
        for (; str[i]!='\0'; i++) {
            str[i-1] = str[i];
        }
        str[i-1] = str[i];
        removeDuplicates(str);
    }
}


int main() {

    char str[100];
    cin >> str;
    removeDuplicates(str);
    cout << str << endl;

    return 0;
}