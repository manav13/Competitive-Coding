class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = 1;

        vector<vector<int>> directions = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        
        while(!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();

            for(auto dir : directions) {
                int newRow = node.first + dir[0];
                int newCol = node.second + dir[1];

                if(newRow >= 0 && newCol >= 0 && newRow < m && newCol < n) {
                    if(!visited[newRow][newCol] && image[newRow][newCol] == image[node.first][node.second]) {
                        q.push({newRow, newCol});
                        visited[newRow][newCol] = 1;
                    }
                }
            }
            image[node.first][node.second] = color;
        }

        return image;
    }
};