class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;
        for(auto i : nums) {
            x ^= i;
        }
        int div = 1;
        while((div & x) == 0) {
            div <<= 1;
        }
        int a = 0, b = 0;
        for(auto i : nums) {
            if(i & div) a ^= i;
            else b ^= i;
        }
        return {a, b};
    }
};