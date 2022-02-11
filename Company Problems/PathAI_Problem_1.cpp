// Name - Binge Watching
#include<bits/stdc++.h>
using namespace std;

int findMinimumDays(vector<float> durations) {
    int size = durations.size();
    sort(durations.begin(), durations.end());
    int count = 0;
    vector<int> dayConsidered(size, 0);
    for(int i=0; i<size; i++) {
        if(dayConsidered[i] == 1) continue;
        if(durations[i] >= 2) {
            count++;
        }
        else {
            int index = upper_bound(durations.begin()+i+1, durations.end(), 3.0-durations[i]) - durations.begin()-1;
            
            while(dayConsidered[index]!=0 && index>i) {
                index--;
            }

            if(durations[i]+durations[index] <= 3.0) {
                count++;
                dayConsidered[index] = 1;
            }
            else {
                count++;
            }
        }
        dayConsidered[i] = 1;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<float> units(n);
    for(int i=0; i<n; i++) {
        cin >> units[i];
    }
    cout << findMinimumDays(units) << endl;
    return 0;
}