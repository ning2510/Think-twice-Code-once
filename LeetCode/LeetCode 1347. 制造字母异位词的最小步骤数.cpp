class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map <char, int> ss;
        for(auto &x : s) {
            ss[x]++;
        }
        for(auto &x : t) {
            if(ss.count(x) && ss[x] > 0) {
                ss[x]--;
            }
        }
        int ans = 0;
        for(auto &x : ss) {
            ans += x.second;
        }
        return ans;
    }
};