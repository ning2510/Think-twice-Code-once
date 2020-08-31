class Solution {
public:
    int n, sum = 0;
    bool ans = false;
    vector <int> vis;
    vector<vector<int>> cnt;

    void dfs(int x) {
        vis[x] = 1;
        sum++;
        if(sum == n) {
            ans = true;
            return ;
        }
        for(auto &c : cnt[x]) {
            if(vis[c]) continue;
            dfs(c);
        }
        return;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        cnt = rooms;
        vis.resize(n, 0);
        dfs(0);
        return ans;
    }
};