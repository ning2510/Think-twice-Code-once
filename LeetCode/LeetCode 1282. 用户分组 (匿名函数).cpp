class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector <pair<int, int>> ss;
        int n = groupSizes.size();
        for(int i = 0; i < n; i++) {
            ss.push_back({i, groupSizes[i]});
        }
        sort(ss.begin(), ss.end(), [](auto &x, auto &y) {
            return x.second < y.second;
        });
        vector <vector<int>> ans;
        int i = 0;
        while(i < n) {
            int now = 0;
            auto &[id, x] = ss[i];
            ans.push_back(vector <int> ());
            while(i < n && ss[i].second == x) {
                if(now < x) {
                    ans.back().push_back(ss[i].first);
                    now++;
                    i++;
                }
                else break;
            }
        }
        return ans;
    }
};