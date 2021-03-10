#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    vector< pair<int, string> > symbols = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
    string result = "";
    int i=0;
    while(num) {
        if(num >= symbols[i].first) {
            result += symbols[i].second;
            num -= symbols[i].first;
        }
        else ++i;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << intToRoman(n) << endl;
}