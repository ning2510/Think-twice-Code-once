class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        for(int i = 0; i < n; i++) {
            if(2 * i >= n) break;
            int x = nums[2 * i], y = nums[2 * i + 1];
            for(int j = 1; j <= x; j++) {
                ans.push_back(y);
            }
        }
        return ans;
    }
};