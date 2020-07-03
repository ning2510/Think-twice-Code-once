class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector <int> ss = heights;
        sort(ss.begin(), ss.end());
        int ans = 0;
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != ss[i]) ans++;
        }
        return ans;
    }
};