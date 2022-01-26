#include<bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers) {
    int size = numbers.size();
    if(numbers[0] == numbers[2]) return "none";
    bool isIncr = (numbers[0] < numbers[2]);

    for(int i=2; i<size; i+=2) {
        if(i+2 >= size) break;
        if((numbers[i] < numbers[i+2]) != isIncr) return "none"; 
    }
    return (isIncr ? "increasing" : "decreasing");
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i=0; i<n; i++) {
        cin >> numbers[i];
    }
    cout << solution(numbers) << endl;
    return 0;
}