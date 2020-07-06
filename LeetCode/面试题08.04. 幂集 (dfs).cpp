class Solution {
public:
    vector <vector<int>> ans;
    vector <int> ss;

    void dfs(int x, vector<int>& nums) {
        if(x == nums.size()) {
            ans.push_back(ss);
            return ;
        }
        dfs(x + 1, nums);
        ss.push_back(nums[x]);
        dfs(x + 1, nums);
        ss.pop_back();
        return ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};