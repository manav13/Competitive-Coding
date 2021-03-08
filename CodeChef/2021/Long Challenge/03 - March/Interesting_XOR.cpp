#include<bits/stdc++.h>
using namespace std;

// string convert2Bin(long long int num) {
//     if(num == 1) return "1";
//     string result = "";
//     long long int size = 0;
//     long long int n = num;
//     while(n) {
//         if(n%2 == 0) result = '0' + result;
//         else {
//             result = '1' + result;
//         }
//         n = long long int(n/2);
//         ++size;
//     }
//     return result;
// }

// long long int findMax(long long int num) {
//     // string n = convert2Bin(num);
//     string n = "100101";
//     string a = "", b = "";
//     long long int size = n.length();
//     for(long long int i=size-1; i>=0; i--) {
//         if(i==0) {
//             a = '1' + a;
//             b = '0' + b;
//         }
//         else if(n[i] == '0') {
//             a = '1' + a;
//             b = '1' + b;
//         }
//         else {
//             a = '0' + a;
//             b = '1' + b;
//         }
//     }
//     long long int A = stoi(a, 0, 2);
//     long long int B = stoi(b, 0, 2);
//     long long int N = stoi(n, 0, 2);
//     cout << "N: " << N << endl;
//     cout << a << ": " << A << endl;
//     cout << b << ": " << B << endl;
//     return A * B;
// }

long long int findNumOfBits(long long int num){
    long long int size = 0;
    while(num) {
        num = num/2;
        ++size;
    }
    return size;
}
long long int findMax(long long int num) {
    long long int size = findNumOfBits(num);
    long long int b = pow(2, size-1) - 1;
    long long int a = num ^ b;
    return a*b;
}

int main() {
    long long int t;
    cin >> t;

    while(t) {
        long long int n;
        cin >> n;
        // cout << convert2Bin(n) << endl;
        cout << findMax(n) << endl;
        --t;
    }
}