class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, ans = 0;
        for(auto &x : nums) {
            sum += x;
            ans = min(ans, sum);
        }
        ans = max(1, 1 - ans);
        return ans;
    }
};