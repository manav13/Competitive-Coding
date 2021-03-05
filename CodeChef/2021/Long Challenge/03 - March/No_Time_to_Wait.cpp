#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, h, x;
    cin >> n >> h >> x;

    int timeNeeded = h - x;
    int flag = 0;
    while(n) {
        int temp;
        cin >> temp;

        if(temp == timeNeeded) flag = 1;
        --n;
    }
    cout << (flag == 1 ? "YES" : "NO") << endl;

    return 0;
}