#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t!=0) {
        
        int n, result;
        cin >> n;
        map<int, int> pos;
        map<int, int> distance;
        int *a = new int[n];
        for (int i=0; i<n; i++) {
            int tmp;
            cin >> tmp;
            a[i] = tmp;
            pos[tmp] = i;
        }
        for (int i=0; i<n; i++) {
            cin >> distance[a[i]];
        }

        result = 0;
        for (int i=2; i<=n; i++) {
            if (pos[i] <= pos[i-1]) {
                while(pos[i] <= pos[i-1]) {
                    pos[i] += distance[i];
                    result++;
                }
            }
        }
        
        cout << result << endl;
        t--;
        
    }
    return 0;
}