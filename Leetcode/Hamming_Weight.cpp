#include<bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
    int result = 0;
    while(n) {
        result += (n%2==0 ? 0 : 1);
        n = int(n/2);
    }
    
    return result;
}

int main() {
    uint32_t n;
    cin >> n;

    cout << hammingWeight(n) << endl;
}