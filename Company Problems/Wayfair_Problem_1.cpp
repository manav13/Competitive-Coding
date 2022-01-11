#include<bits/stdc++.h>
using namespace std;

string solution(string &S, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    string msg = "";
    msg += S[0];
    int i = 0;
    while (A[i]!=0) {
        msg += S[A[i]];
        i = A[i];
    }
    return msg;
}

int main() {
    
    string S;
    vector<int> A;

    cin >> S;
    int n;

    cin >> n;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    cout << solution(S, A) << endl;

    return 0;
}