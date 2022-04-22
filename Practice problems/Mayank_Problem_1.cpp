#include<bits/stdc++.h>
using namespace std;

void subtractOne(string &number, int &count) {
    int size = number.size();
    // int index = size-1;
    for(int i=size-1; i>=0; i--) {
        // Find rightmost one
        if(number[i] == '1') {
            count--;
            number[i] = '0';
            break;
        }
        else {
            count++;
            number[i] = '1';
        }
    }
}

vector<int> solution(string number, vector<string> requests) {
    vector<int> output;
    // Initial ones count
    int count = 0;
    for(auto n : number) {
        if(n == '1')
            count++;
    }

    for(auto req : requests) {
        if(req == "?") {
            output.push_back(count);
        }
        else {
            subtractOne(number, count);
        }
    }
    return output;
}

int main() {
    vector<int> ans;
    string number = "10000";
    vector<string> requests = {"?", "-", "?", "-", "?", "-", "?"};

    ans = solution(number, requests);
    for(auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}