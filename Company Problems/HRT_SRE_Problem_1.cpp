#include<bits/stdc++.h>
using namespace std;

int solution(string &S) {
    int size = S.size();
    int count = 0;
    for(int i=0; i<size; i++) {
        if(S[i] == '1') break;
        else count++;
    }
    int ans = 0;
    for(int i=size-1; i>=count; i--) {
        if(S[i] == '0') ans += 1;
        else {
            if(i == count) ans+=1;
            else ans+=2;
        }
    }
    return ans;
}

int main() {
    return 0;
}