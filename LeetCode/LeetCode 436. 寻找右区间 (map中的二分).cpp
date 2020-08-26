class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map <int, int> ss;
        for(int i = 0; i < n; i++) {
            ss[intervals[i][0]] = i;
        }
        vector <int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            int x = intervals[i][1];
            auto it = ss.lower_bound(x);
            if(it != ss.end()) ans[i] = it->second;
        }
        return ans;
    }
};