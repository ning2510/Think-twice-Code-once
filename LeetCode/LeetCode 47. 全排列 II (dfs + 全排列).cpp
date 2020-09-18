class Solution {
public:
    int n;
    vector <int> ss;
    vector <vector<int>> ans;

    void dfs(int x, vector<int>& vis, vector<int>& nums) {
        if(x == n) {
            ans.push_back(ss);
            return ;
        }
        for(int i = 0; i < n; i++) {
            if(vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) continue;
            vis[i] = 1;
            ss.push_back(nums[i]);
            dfs(x + 1, vis, nums);
            ss.pop_back();
            vis[i] = 0;
        }
        return ;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector <int> vis(n, 0);
        sort(nums.begin(), nums.end());
        dfs(0, vis, nums);
        return ans;
    }
};