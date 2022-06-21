#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    int climbStairsRecursion(int n, vector<int> &stepTaken) {
        if(n==0) return 1;
        if(n<0) return 0;
        if(stepTaken[n] != -1) return stepTaken[n];
        
        int takeOneStep = climbStairsRecursion(n-1, stepTaken);
        int takeTwoStep = climbStairsRecursion(n-2, stepTaken);
        
        stepTaken[n] = takeOneStep + takeTwoStep;
        
        return stepTaken[n];
    } 
    
    
    int climbStairs(int n) {
        vector<int> stepTaken(n+1, -1);
        return climbStairsRecursion(n, stepTaken);
    }
};

int main() {
    return 0;
}