class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector <vector<int>> ss;
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            int k = n - 1, sum = -nums[i];
            for(int j = i + 1; j < n; j++) {
                if(j > i + 1 && nums[j - 1] == nums[j]) continue;
                while(j < k && nums[j] + nums[k] > sum) k--;
                if(j == k) break;
                if(nums[j] + nums[k] == sum) ss.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ss;
    }
};