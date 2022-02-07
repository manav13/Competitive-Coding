// Name - Circular Printer
#include<bits/stdc++.h>
using namespace std;

long timeToPrint(char a, char b){
    long P=abs(a-b);
    long Q=26-P;
    return min(P, Q);
}

long getTime(string s) {
   long cnt=0;
   char last ='A';
   for(auto curr: s){
       cnt+=timeToPrint(last, curr);
       last=curr;
   }
   return cnt;
}

int main() {
    return 0;
}