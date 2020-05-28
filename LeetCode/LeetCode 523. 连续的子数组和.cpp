class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> ss;
        int x = 0;
        ss[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            x += nums[i];
            if(k != 0) x = x % k;
            if(ss.count(x)) {
                if(i - ss[x] > 1) return true;
            }
            else ss[x] = i;
        }
        return false;
    }
};