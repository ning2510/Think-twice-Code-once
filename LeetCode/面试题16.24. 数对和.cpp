class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map <int, int> ss;
        vector <vector<int>> ans;
        for(auto &x : nums) {
            int y = target - x;
            if(ss.count(y) && ss[y] > 0) {
                ss[y]--;
                ans.push_back({x, y});
            }
            else ss[x]++;
        }
        return ans;
    }
};