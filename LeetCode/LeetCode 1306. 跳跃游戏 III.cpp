class Solution {
public:
    int n, flag = 0;

    void dfs(int x, vector<int>& arr, vector<int>& vis) {
        if(flag) return ;
        if(arr[x] == 0) {
            flag = 1;
            return ;
        }
        vis[x] = 1;
        if(x + arr[x] >= 0 && x + arr[x] < n && !vis[x + arr[x]]) dfs(x + arr[x], arr, vis);
        if(x - arr[x] >= 0 && x - arr[x] < n && !vis[x - arr[x]]) dfs(x - arr[x], arr, vis);
        return ;
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector <int> vis(n, 0);
        dfs(start, arr, vis);
        return flag;
    }
};