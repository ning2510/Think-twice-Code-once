class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector <vector<int>> ss;
        for(auto &x : words) {
            int t = 0;
            ss.push_back(vector <int> ());
            for(auto &y : x) {
                int m = (1 << (y - 'a'));
                t |= m;
            }
            ss.back().push_back(t);
            ss.back().push_back(x.size());
        }
        int ans = 0;
        for(int i = 0; i < ss.size(); i++) {
            for(int j = i + 1; j < ss.size(); j++) {
                if(ss[i][0] & ss[j][0]) continue;
                ans = max(ans, ss[i][1] * ss[j][1]);
            }
        }
        return ans;
    }
};