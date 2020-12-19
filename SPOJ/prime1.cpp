#include <iostream>
#include <math.h>
using namespace std;

bool isPrime (int num){
    if (num == 1 || num == 0){
        return false;
    }
    else if (num == 2){
        return true;
    }
    else {
        for (int i=2; i<=int(sqrt(num)); ++i){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
}

int main() {
    int t;
    cin >> t;
    while (t){
        int lower, upper;
        cin >> lower >> upper;
        for (int num = lower; num <= upper; ++num){
            if (isPrime(num)){
                cout << num << "\n";
            }
        }
        cout << endl;
        --t;
    }
    return 0;
}