// Name - Astronomy Board Game
#include<bits/stdc++.h>
using namespace std;

int removeIndicesToMakeSumEqual(vector<int>& planets)
{
    int N = planets.size();
    vector<int> odd(N, 0);
    vector<int> even(N, 0);
    even[0] = planets[0];
 
    for (int i = 1; i < N; i++) {
        odd[i] = odd[i - 1];
        even[i] = even[i - 1];
        if (i % 2 == 0) {
            even[i] += planets[i];
        }
        else {
            odd[i] += planets[i];
        }
    }
    bool find = 0;
    int p = odd[N - 1];
    int q = even[N - 1] - planets[0];
    if (p == q) {
        return 1;
        find = 1;
    }
    for (int i = 1; i < N; i++) {
        if (i % 2 == 0) {
            p = even[N - 1] - even[i - 1] - planets[i] + odd[i - 1];
            q = odd[N - 1] - odd[i - 1] + even[i - 1];
        }
        else {
            q = odd[N - 1] - odd[i - 1] - planets[i] + even[i - 1];
            p = even[N - 1] - even[i - 1] + odd[i - 1];
        }
        if (p == q) {
            find = 1;
            return i+1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2,5,3,1};
    cout << removeIndicesToMakeSumEqual(arr) << endl;
    return 0;
}