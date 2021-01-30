#include<bits/stdc++.h>
using namespace std;

int main() {
    int num;
    int prod = 1;
    cin >> num;
    while(num!=0) {
        prod *= num%10;
        num = int(num/10);
    }
    cout << prod;

    return 0;
}