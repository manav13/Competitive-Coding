// Quora - maximum consecutive houses at a time
#include<bits/stdc++.h>
using namespace std;

void updateHouses(vector<int> &houses, int val, int left, int right) {
    while(left>0) {
        if(houses[left] == 0) break;
        else houses[left] = val;
        left--;
    }

    while(right < houses.size()) {
        if(houses[right] == 0) return;
        else {
            houses[right] = val;
        }
        right++;
    }
}

vector<int> compute(vector<int> queries) {
    int min = *min_element(queries.begin(), queries.end());
    int max = *max_element(queries.begin(), queries.end());

    vector<int> houses(max - min + 1, 0);
    int size = queries.size();
    vector<int> result(size, 0);

    for(int i=0; i<size; i++) {
        if(queries[i] == min) {
            if(houses[1] == 0) houses[0] = 1;
            else {
                houses[0] = houses[1] + 1;
                updateHouses(houses, houses[0], 0, 1);
            }
        }
        else if (queries[i] == max) {
            if(houses[max-min-1] == 0) houses[max-min] = 1;
            else {
                houses[max-min] = houses[max-min-1] + 1;
                updateHouses(houses, houses[max-min], max-min-1, max-min);
            }
        }
        else {
            int index = queries[i]-min;
            houses[index] = houses[index-1] + houses[index+1] + 1;
            updateHouses(houses, houses[index], index-1, index+1); 
        }
        result[i] = *max_element(houses.begin(), houses.end());;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> queries;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        queries.push_back(temp);
    }

    vector<int> result = compute(queries);
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}