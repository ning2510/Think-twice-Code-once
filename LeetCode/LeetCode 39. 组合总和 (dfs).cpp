class Solution {
public:
    vector <int> ss;
    vector <vector<int>> ans;

    void dfs(int n, int sum, int target, vector<int>& candidates) {
        if(sum == target) {
            ans.push_back(ss);
            return ;
        }
        for(int i = n; i < candidates.size(); i++) {
            if(sum + candidates[i] > target) break;
            ss.push_back(candidates[i]);
            dfs(i, sum + candidates[i], target, candidates);
            ss.pop_back();
        }
        return ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, target, candidates);
        return ans;
    }
};