class Solution {
public:
    int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;
        int n = image.size(), m = image[0].size();
        vector <vector<int>> vis(n, vector<int>(m, 0));
        queue <pair<int, int>> ss;
        ss.push({sr, sc});
        image[sr][sc] = newColor;
        vis[sr][sc] = 1;
        while(!ss.empty()) {
            auto k = ss.front();
            ss.pop();
            for(int i = 0; i < 4; i++) {
                int now_x = k.first + dir[i][0];
                int now_y = k.second + dir[i][1];
                if(now_x < 0 || now_x >= n || now_y < 0 || now_y >= m || vis[now_x][now_y]) continue;
                if(image[now_x][now_y] != oldColor) continue;
                vis[now_x][now_y] = 1;
                image[now_x][now_y] = newColor;
                ss.push({now_x, now_y});
            }
        }
        return image;
    }
};