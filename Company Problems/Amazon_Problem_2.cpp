#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

vector<int> compute(vector<int> locations, vector<int> movedFrom, vector<int> movedTo) {
    int n = locations.size();
    int m = movedFrom.size();

    sort(locations.begin(), locations.end());
    for(int i=0; i<m; i++) {
        int index = binarySearch(locations, 0, n-1, movedFrom[i]);
        locations[index] = movedTo[i];
    }
    sort(locations.begin(), locations.end());
    return locations;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> locations;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        locations.push_back(temp);
    }
    vector<int> movedFrom;
    vector<int> movedTo;
    for(int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        movedFrom.push_back(temp);
    }

    for(int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        movedTo.push_back(temp);
    }

    vector<int> result = compute(locations, movedFrom, movedTo);
    for(int i=0; i<n; i++) {
        cout << result[i] << endl;
    }
    return 0;
}