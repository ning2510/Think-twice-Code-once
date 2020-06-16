class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map <string, int> ss;
        for(auto &x : dominoes) {
            int a = x[0], b = x[1];
            if(a > b) swap(a, b);
            string s = to_string(a);
            s += to_string(b);
            ss[s]++;
        }
        int ans = 0;
        for(auto &x : ss) {
            ans += x.second * (x.second - 1) / 2;
        }
        return ans;
    }
};