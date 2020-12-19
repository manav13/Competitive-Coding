#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int j=0; j<t; j++){
        long long int sum=0;
        int n,a;
        cin>>n>>a;
        int newMat = a;
        for (int i=1; i<n*2; i+=2){
            int numMul = pow(newMat, i);
            sum += numMul;
            newMat = numMul * newMat;
        }
        int result = fmod(sum,(pow(10,9)+7));
        cout<<result<<"\n";
    }

    return 0;
}
