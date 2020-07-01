/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月24日 星期二 16时52分42秒
 ************************************************************************/

class Solution {
public:
    int massage(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int ans = 0, f[1005] = {0};
        f[0] = nums[0];
        if(len > 1) f[1] = nums[1];
        if(len > 2) f[2] = f[0] + nums[2];
        ans = max(f[0], max(f[1], f[2]));
        for(int i = 3; i < len; i++) {
            f[i] = max(f[i - 2], f[i - 3]) + nums[i];
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
