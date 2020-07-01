/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 12时33分55秒
 ************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(!len) return 0;
        vector<int> maxn(len, 0);
        maxn[0] = 0;
        for(int i = 1; i < len; i++) {
            if(height[i] > height[maxn[i - 1]]) maxn[i] = i;
            else maxn[i] = maxn[i - 1];
        }
        int ans = 0;
        for(int i = 1; i < len; i++) {
            if(height[i] > height[i - 1]) {
                if(i == 1) continue;
                if(height[maxn[i - 1]] <= height[i]) {
                    int h = height[maxn[i - 1]];
                    for(int j = maxn[i - 1] + 1; j < i; j++) {
                        ans += h - height[j];
                        height[j] = h;
                    }
                }
                else {
                    for(int j = i - 1; height[j] <= height[i] && j >= 0; j--) {
                        ans += height[i] - height[j];
                        height[j] = height[i];
                    }
                }
            }
        }
        return ans;
    }
};
