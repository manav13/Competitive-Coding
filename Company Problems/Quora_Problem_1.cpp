// Quora - Sorted Alternating pattern
#include<bits/stdc++.h>
using namespace std;

vector<int> findPattern(vector<int> numbers, int size) {
    vector<int> pattern;
    pattern.push_back(numbers[0]);
    for(int i=1; i<size; i++) {
        if(numbers[i] > numbers[i-1]) pattern.push_back(numbers[i]);
        else break;
    }
    return pattern;
}

int compute(vector<int> numbers) {
    int size = numbers.size();
    vector<int> pattern = findPattern(numbers, size);
    int patternSize = pattern.size();
    int result = -1;
    for(int i=0; i<size; i+=patternSize) {
        for(int j=0; j<patternSize; j++) {
            if(numbers[j+i] != pattern[j]) {
                result = j+i;
                break;
            }
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    cout << compute(numbers) << endl;
}