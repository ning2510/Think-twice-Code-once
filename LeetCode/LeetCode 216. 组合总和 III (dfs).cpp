class Solution {
public:
    vector <int> dict;
    vector <int> ss;
    vector <vector<int>> ans;

    void dfs(int x, int cnt, int sum, int k, int n) {
        if(sum > n || cnt > k) return ;
        if(cnt == k) {
            if(sum == n) ans.push_back(ss);
            return ;
        }
        for(int i = x; i < dict.size(); i++) {
            if(sum + dict[i] > n) break;
            ss.push_back(dict[i]);
            dfs(i + 1, cnt + 1, sum + dict[i], k, n);
            ss.pop_back();
        }
        return ;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        for(int i = 1; i <= 9; i++) {
            dict.push_back(i);
        }
        dfs(0, 0, 0, k, n);
        return ans;
    }
};