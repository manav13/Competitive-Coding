#include <bits/stdc++.h>
using namespace std;

// Function to print the maximum number
int solution(int num)
{
    int count[10] = {0};

    string str = to_string(num);
 
    for (int i=0; i<str.length(); i++)
        count[str[i]-'0']++;

    int result = 0, multiplier = 1;
    int maxDigit = 9;
   
    for(int i=0; i<str.length(); i++) {
        if(str[i] == maxDigit && count[str[i]-'0'] > 0) {
            count[str[i]-'0']--;
        }
        else if(str[i] != maxDigit) {
            // find the right most max Digit
            int rightPointer = str.length()-1;
            while(true) {
                if(int(str[rightPointer]) == maxDigit) {
                    // Incompelete logic....
                }
            }
        }
    }
 
    // return the result
    return result;
}
 
// Driver program to test above function
int main()
{
    int num = 1080;
    cout << printMaxNum(num);
    return 0;
}