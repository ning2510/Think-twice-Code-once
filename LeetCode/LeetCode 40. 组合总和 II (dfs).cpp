class Solution {
public:
    int n;
    vector <int> ss;
    vector <vector<int>> ans;

    void dfs(int x, int sum, int target, vector<int>& candidates) {
        if(sum > target) return ;
        if(sum == target) {
            ans.push_back(ss);
            return ;
        }
        for(int i = x; i < n; i++) {
            if(i > x && candidates[i] == candidates[i - 1]) continue;
            ss.push_back(candidates[i]);
            dfs(i + 1, sum + candidates[i], target, candidates);
            ss.pop_back();
        }
        return ;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        dfs(0, 0, target, candidates);
        return ans;
    }
};