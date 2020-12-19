#include <iostream>

using namespace std;

int main () {
    int isTrue = 1;
    while(isTrue){
        int n;
        cin >> n;
        if (n != 42){
            cout << n << endl;
        }
        else {
            isTrue = 0;
        }
    }
    return 0;
}