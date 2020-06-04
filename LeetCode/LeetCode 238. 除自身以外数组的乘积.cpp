class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int x = 1, n = nums.size();
        vector <int> ss(n, 0);
        for(int i = 0; i < n; i++) {
            ss[i] = x;
            x *= nums[i];
        }
        x = 1;
        for(int i = n - 1; i >= 0; i--) {
            ss[i] *= x;
            x *= nums[i];
        }
        return ss;
    }
};