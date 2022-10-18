#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        
        int size = s.size();
        
        // Remove leading white spaces
        int i = 0;
        while(s[i] == ' ') {
            i++;
        }
        
        long ans = 0; 
        int sign = 1;

        if(s[i] == '+') {
            i++;
        }
        else if(s[i] == '-') {
            sign = -1;
            i++;
        }
        
        while(i<size) {
            int digit = s[i] - '0';
            if(digit < 0 || digit > 9)
                break;
            
            ans = ans*10 + digit;
            
            if(sign == -1 && -1*ans < INT_MIN) return INT_MIN;
            if(sign == 1 && ans > INT_MAX) return INT_MAX;
            
            i++;
        }
        
        return (int)(ans*sign);
    }
};

int main() {
    return 0;
}