#include<bits/stdc++.h>
using namespace std;

string compute(int n, vector<int> a) {
    int ansEven = a[0];
    int ansOdd = a[1];
    bool mult = true;
    for(int i=2; i<n; i+=2) {
        if(mult) {
            ansEven *= a[i];
            mult = false;
        }
        else {
            ansEven += a[i];
            mult = true;
        }
    }
    ansEven = abs(ansEven)%2;
    mult = true;
    for(int i=3; i<n; i+=2) {
        if(mult) {
            ansOdd *= a[i];
            mult = false;
        }
        else {
            ansOdd += a[i];
            mult = true;
        }
    }
    ansOdd = abs(ansOdd)%2;

    if(ansEven > ansOdd) return "EVEN";
    else if(ansEven < ansOdd) return "ODD";
    else return "NEUTRAL";
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    string ans = compute(n, a);
    cout << ans << endl;
    return 0;
}