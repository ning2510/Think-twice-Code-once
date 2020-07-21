class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(auto &x : nums) {
            ans += abs(nums[nums.size() / 2] - x);
        }
        return ans;
    }
};