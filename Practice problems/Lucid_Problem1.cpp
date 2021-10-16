#include<bits/stdc++.h>
using namespace std;

int getIndex(vector<int> answer, int key) {
    // if (high - low == 1)
    //     return high;
    // int mid = (low + high) / 2; /*low + (high - low)/2;*/
    // if (key == answer[mid])
    //     return mid;
    // if (key > answer[mid])
    //     return getIndex(answer, (mid), high, key);
    // return getIndex(answer, low, (mid), key);

    int low = 0;
    int high = answer.size()-1;
    int index;
    while(true) {
        index = (int) ((high + low)/2);
        if(low == index) {
            if(answer[index] > key) return index;
        }
        if(answer[index] < key) {
            low = index + 1;
            if(low > high) return index+1;
        }
        else if (low > high) return index;
        else high = index - 1;
    }
}

long compute(vector<int> numbers) {
    int size = numbers.size();
    
    // Initial insertion
    long result = 1;
    vector<int> answer;
    answer.push_back(numbers[0]);
    int k = 0;
    for(int i=1; i<size; i++) {
        if(numbers[i] <= answer[0]) {
            answer.insert(answer.begin(), numbers[i]);
            result += 1;
            k=0;
        }
        else if (numbers[i] >= answer[answer.size()-1]) {
            answer.push_back(numbers[i]);
            result += 1;
            k=0;
        }
        else {
            int index = getIndex(answer, numbers[i]);
            // cout << "index: " << index << endl;
            if(index <= ( answer.size()-index)) {
                result += (index*2);
                result += 1;
            }
            else {
                result += ((answer.size()-index-1)*2);
                result += 1;
            }
            answer.insert(answer.begin()+index, numbers[i]);
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
    return 0;
}