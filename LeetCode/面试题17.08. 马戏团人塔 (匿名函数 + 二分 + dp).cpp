class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector <pair<int, int>> ss;
        for(int i = 0; i < height.size(); i++) {
            ss.push_back({height[i], weight[i]});
        }
        sort(ss.begin(), ss.end(), [](auto x, auto y) {
            return x.first == y.first ? x.second > y.second : x.first < y.first;
        });
        vector <int> dp;
        for(auto &[h, w] : ss) {
            auto p = lower_bound(dp.begin(), dp.end(), w);
            if(p == dp.end()) dp.push_back(w);
            else *p = w;    //dp[p - dp.begin()] = w;
        }
        return dp.size();
    }
};