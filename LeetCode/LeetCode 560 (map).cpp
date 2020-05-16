class Solution {
    int sum[20005] = {0};

public:
    int subarraySum(vector<int>& nums, int k) {
        map <int, int> ss;
        int ans = 0;
        ss[0]++;
        sum[0] = nums[0];
        ans += ss[sum[0] - k];
        ss[sum[0]]++;
        for(int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i];
            ans += ss[sum[i] - k];
            ss[sum[i]]++;
        }
        return ans;
    }
};