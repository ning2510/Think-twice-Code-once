class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(!nums[i]) continue;
            int k = i + 2;
            for(int j = i + 1; j < nums.size() - 1; j++) {
                while(k < nums.size() && nums[i] + nums[j] > nums[k]) k++;
                ans += k - j - 1;
            }
        }
        return ans;
    }
};