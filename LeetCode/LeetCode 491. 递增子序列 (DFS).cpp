class Solution {
public:
    vector <int> ss;
    vector <vector<int>> ans;

    void dfs(int x, int last, vector<int>& nums) {
        if(x == nums.size()) {
            if(ss.size() >= 2) {
                ans.push_back(ss);
            }
            return ;
        }
        if(nums[x] >= last) {
            ss.push_back(nums[x]);
            dfs(x + 1, nums[x], nums);
            ss.pop_back();
        }
        if(nums[x] != last) dfs(x + 1, last, nums);
        return ;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, INT_MIN, nums);
        return ans;
    }
};