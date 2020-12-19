#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int t;
    cin >> t;
    while (t!=0) {
        long long int row, col, ans;
        cin >> row >> col;
        long long int n = (row > col) ? row : col;
        long long int cornerValue = n*n - n + 1;
        if (row==col) {
            ans = cornerValue;
        }
        else if (n%2==0) {
            if (row > col) {
                ans = cornerValue + (row-col);
            } else {
                ans = cornerValue - (col-row);
            }
        } else {
            if (row > col) {
                ans = cornerValue - (row-col);
            } else {
                ans = cornerValue + (col-row);
            }
        }
        cout << ans << endl;
        t--;
    }
    return 0;
}