// Name - Compress and encrypt things

#include<bits/stdc++.h>
using namespace std;

string compress(string thestring) {
    string s = "";
    int size = thestring.size();
    int firstPointer = 0, secondPointer = 0;

    while(secondPointer <= size) {
        if(thestring[secondPointer] != thestring[firstPointer] || secondPointer == size) {
            int n = secondPointer - firstPointer;

            ostringstream ss;
            string hexString;
            ss << std::hex << n;

            s += thestring[firstPointer];
            if(n == 1) {
                s += "1";
            }
            else {
                s += ss.str();
            }
            firstPointer = secondPointer;
        }
        secondPointer++;
    }
    reverse(s.begin(), s.end()); 
    return s;
}

int main() {

    cout << compress("aaaaaaaaaaa") << endl;

    return 0;
}