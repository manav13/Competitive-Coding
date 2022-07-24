#include<bits/stdc++.h>

using namespace std;

int solution(string S) {
  int minLetterCount = 0;
  string repeatingString = "abc";
  
  int size = S.size();
  int i=0, j=0;
  
  while(i<size) {
    j = j%3;
    if(S[i] == repeatingString[j]) {
      i++;
      j++;
    }
    else {
      minLetterCount++;
      j++;
    }
  }
  
  return minLetterCount;
}

int main() {
    return 0;
}