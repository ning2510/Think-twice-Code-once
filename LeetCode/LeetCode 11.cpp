/*************************************************************************
	> File Name: bbb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月18日 星期六 12时16分33秒
 ************************************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxn = 0, l = 0, r = height.size() - 1;
        while(l <= r) {
            maxn = max(maxn, min(height[l], height[r]) * (r - l));
            if(height[l] >= height[r]) r--;
            else l++;
        }
        return maxn;
    }
};
