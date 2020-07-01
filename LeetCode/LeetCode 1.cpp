/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 15时01分08秒
 ************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> ss;
        for(int i = 0; i < nums.size(); i++) {
            ss[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if(ss.count(t) && ss[t] != i) {
                return {ss[t], i};
            }
        }
        return {};
    }
};
