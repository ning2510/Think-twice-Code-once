class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto &x : nums) {
            int t = (int)log10((double)x) + 1;
            if(!(t & 1)) ans++;
        }
        return ans;
    }
};