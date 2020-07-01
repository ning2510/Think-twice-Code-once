/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月02日 星期六 21时45分51秒
 ************************************************************************/

class Solution {
    int vis[20] = {0};
    int dfs(int x, int now, vector <int> nums) {
        if(now == 0) return true;
        for(int i = x; i >= 0; i--) {
            if(vis[i]) continue;
            if(now < nums[i]) continue;
            vis[i] = 1;
            if(dfs(i, now - nums[i], nums)) return true;
            vis[i] = 0;    
        }
        return false;    
    }

    public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() == 0) return false;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];        
        }
        if(sum % 4 != 0) return false;
        int ave = sum / 4;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < 4; i++) {
            if(!dfs(nums.size() - 1, ave, nums)) return false;        
        }
        return true;    
    }
};
