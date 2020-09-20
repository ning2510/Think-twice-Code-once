class Solution {
public:
    int n;
    vector <int> ss;
    vector <vector<int>> ans;

    void dfs(int x, vector<int>& nums) {
        if(x == n) {
            ans.push_back(ss);
            return ;
        }
        ss.push_back(nums[x]);
        dfs(x + 1, nums);
        ss.pop_back();
        dfs(x + 1, nums);
        return ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        dfs(0, nums);
        return ans;
    }
};