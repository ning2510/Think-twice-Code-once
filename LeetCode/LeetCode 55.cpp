/*************************************************************************
	> File Name: bbb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月18日 星期六 11时56分34秒
 ************************************************************************/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int now = 0;
        for(int i = 0; i < n; i++) {
            if(i <= now) {
                now = max(now, i + nums[i]);
                if(now >= n - 1) return true;
            }
        }
        return false;
    }
};
