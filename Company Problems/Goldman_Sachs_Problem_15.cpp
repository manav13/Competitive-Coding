// Problem Name: Encircular
#include <bits/stdc++.h>
using namespace std;

bool isRobotBounded(string instructions) {
    int x = 0, y = 0, i = 0;
    vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
    for (char & ins : instructions)
        if (ins == 'R')
            i = (i + 1) % 4;
        else if (ins == 'L')
            i = (i + 3) % 4;
        else
            x += d[i][0], y += d[i][1];
    return x == 0 && y == 0 || i > 0;
}

vector<string> doesCircleExist(vector<string> commands) {
    vector<string> ans;

    for(auto c : commands) {
        if(isRobotBounded(c)) ans.push_back("YES");
        else ans.push_back("NO");
    }

    return ans;
}