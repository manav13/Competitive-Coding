#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> A) {
  bool flag1 = false, flag2 = false;
  int side1, side2;
  map<int, int> hash;
  
  for(auto num : A) {
    hash[num]++;
  }
  auto it=hash.rbegin();
  
  while(it!=hash.rend() && flag2 == false) {
    if(it->second>=2 || it->second%2 == 0) {
      if(flag1 == false) {
        side1 = it->first;
        flag1 = true;
      }
      else if(flag2 == false) {
        side2 = it->first;
        flag2 = true;
      }
      it->second -= 2;
    }
    else {
      it++;
    }
  }
  if(flag1 == false || flag2 == false) return -1;
  return abs(side1-side2);
}

int main() {
    cout << solution({911, 1, 3, 1000, 1000, 2, 2, 999, 1000, 911}) << endl;
}