#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers) {
    int size = numbers.size();
    int finalSum = 0;
    for(int i=0; i<size; i++) {
        if(numbers[i]!=0) {
            int x = numbers[i];
            for(int j=i; j<size; j++) {
                if(numbers[j] < x) {
                    break;
                }
                numbers[j] -= x;
            }
            finalSum += x;
        }
    }
    return finalSum;
}

int main() {
    vector<int> numbers = {3,3,5,2,3};
    cout << solution(numbers) << endl;
    return 0;
}