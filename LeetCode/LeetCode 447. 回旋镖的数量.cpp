class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i++) {
            unordered_map <int, int> ss;
            for(int j = 0; j < points.size(); j++) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                ss[x * x + y * y]++;
            }
            for(auto &x : ss) {
                ans += x.second * (x.second - 1);
            }
        }
        return ans;
    }
};