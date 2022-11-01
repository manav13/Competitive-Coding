#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> image, int radius) {
    int m = image.size(), n = image[0].size();
    vector<vector<int>> result(m, vector<int> (n, 0));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            int sr = i-radius, er = i+radius, sc = j-radius, ec = j+radius;
            int sum = 0, len = 0;
            sr = (sr < 0) ? 0 : sr;
            sc = (sc < 0) ? 0 : sc;
            er = (er >= m) ? m-1 : er;
            ec = (ec >= n) ? n-1 : ec;

            for(int k = sr; k<=er; k++) {
                for(int l = sc; l<=ec; l++) {
                    len++;
                    sum += image[k][l];
                }
            }

            sum -= image[i][j];
            len--;

            if(len == 0) {
                result[i][j] = image[i][j];
            }
            else {
                int avgVal = sum/len;
                avgVal = (avgVal+image[i][j])/2;

                result[i][j] = avgVal;
            }
        }
    }
    return result;
}


int main() {
    vector<vector<int>> image = {
        {9, 6},
        {3, 0}
    };

    vector<vector<int>> result = solution(image, 1);

    for(int i=0; i<image.size(); i++) {
        for(int j=0; j<image[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}