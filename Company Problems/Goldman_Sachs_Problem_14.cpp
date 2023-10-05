// Problem Name: Chairs Requirement
#include <bits/stdc++.h>
using namespace std;

vector<int> minChairs(vector<string> simulations) {
    int size = simulations.size();
    vector<int> ans;
    
    for(auto sim : simulations) {
        int availableChairs = 0;
        int totalChair = 0;
        for(auto c : sim) {
            if(c == 'C' || c == 'U') {
                if(availableChairs == 0) {
                    totalChair++;
                }
                else availableChairs--;
            }
            else if(c == 'R' || c == 'L') {
                availableChairs++;
            }
        }
        ans.push_back(totalChair);
    }
    return ans;
}

int main()
{
    vector<string> simulations = {"CRUL"};
    vector<int> ans = minChairs(simulations);
    
    for(auto num : ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
