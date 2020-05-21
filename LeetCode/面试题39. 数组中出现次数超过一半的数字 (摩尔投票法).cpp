class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sum = 0, ans;
        for(auto x : nums) {
            if(sum == 0) ans = x;
            sum += ans == x ? 1 : -1;
        }
        return ans;
    }
};