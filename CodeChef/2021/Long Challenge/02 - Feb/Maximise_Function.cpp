#include <bits/stdc++.h>
using namespace std;

long long int calculate (long long int a[], long long int size) {

    long long int max = a[0];
    long long int min = a[0];

    for(long long int i=1; i<size; i++) {
        if(max < a[i]) max = a[i];
        if(min > a[i]) min = a[i];
    }
    
    // int sum = abs(a[x]-a[y]) + abs(a[y]-a[z]) + abs(a[z]-a[x]);
    return 2*(max-min);
}

int main () {
    int t;
    cin >> t;

    while (t!=0) {
        long long int n;
        cin >> n;
        long long int *a = new long long int[n];
        for (long long int i=0; i<n; i++) {
            cin >> a[i];
        }
        // merge_sort(a, 0, n-1);

        // int mid = int((n-1)/2);
        // if (n%2!=0) cout << calculate(a, 0, mid, n-1) << endl;
        // else {
        //     int result1 = calculate(a, 0, mid, n-1);
        //     int result2 = calculate(a, 0, mid+1, n-1);

        //     cout << ((result1 > result2) ? result1 : result2) << endl;
        // }
        
        cout << calculate(a, n) << endl;
        t--;
    }
}