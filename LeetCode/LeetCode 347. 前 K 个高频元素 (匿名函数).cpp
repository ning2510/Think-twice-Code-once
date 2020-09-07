class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> ss;
        for(auto &x : nums) {
            ss[x]++;
        }
        vector <vector<int>> pp;
        for(auto &x : ss) {
            pp.push_back({x.first, x.second});
        }
        sort(pp.begin(), pp.end(), [](auto &x, auto &y) {
            return x[1] > y[1];
        });
        vector <int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(pp[i][0]);
        }
        return ans;
    }
};