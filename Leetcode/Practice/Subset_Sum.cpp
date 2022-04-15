#include<bits/stdc++.h>
using namespace std;

void solution(vector<int> num, int index, int sum, int size, vector<int>& output) {
    if(index == size){
        output.push_back(sum);
        return;
    }

    // Pick the element
    solution(num, index+1, sum+num[index], size, output);
    
    // Not pick the element
    solution(num, index+1, sum, size, output);

    return;
}

int main() {

    vector<int> output;

    solution({3,1,2}, 0, 0, 3, output);
    sort(output.begin(), output.end());

    for(auto sums : output) {
        cout << sums << " ";
    }
    cout << endl;
    return 0;
}