/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月23日 星期一 18时05分13秒
 ************************************************************************/

#include <cmath>

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int cnt = 0, sum = 0;
            int sq = sqrt(nums[i]);
            for(int j = 2; j <= sq; j++) {
                if(nums[i] % j == 0) {
                    cnt++;
                    sum += j;
                    sum += nums[i] / j;
                }
                if(cnt > 1) break;
            }
            if(cnt == 1 && sq * sq != nums[i]) {
                ans += sum + 1 + nums[i];
            }
        }
        return ans;
    }
};
