class Solution {
public:
    vector <vector<int>> ss;

    void dfs(int x, int n, vector <int> &nums) {
        if(x == n) {
            ss.push_back(nums);
            return ;
        }
        for(int i = x; i <= n; i++) {
            swap(nums[i], nums[x]);
            dfs(x + 1, n , nums);
            swap(nums[i], nums[x]);
        }
        return ;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return ss;
        dfs(0, nums.size() - 1, nums);
        return ss;
    }
};
