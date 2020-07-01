/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月03日 星期日 10时45分20秒
 ************************************************************************/

class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        long long ans = -2e11, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }
        return ans;
    }

};
