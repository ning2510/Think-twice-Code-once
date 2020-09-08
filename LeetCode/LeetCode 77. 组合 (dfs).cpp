class Solution {
public:
    vector <int> ss;
    vector <vector<int>> ans;

    void dfs(int x, int n, int k) {
        if(ss.size() == k) {
            ans.push_back(ss);
            return ;
        }
        for(int i = x; i <= n; i++) {
            ss.push_back(i);
            dfs(i + 1, n, k);
            ss.pop_back();
        }
        return ;
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};