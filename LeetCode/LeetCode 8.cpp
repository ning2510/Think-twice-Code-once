/*************************************************************************
	> File Name: bbb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月03日 星期五 17时24分38秒
 ************************************************************************/

class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        if(len == 0) return 0;
        int i = 0;
        while(i < len && str[i] == ' ') ++i;
        if(i >= len) return 0;
        bool flag = false;
        if(str[i] == '-') {
            flag = true;
            i++;
        }
        else if(str[i] == '+') i++;
        bool vis = false;
        int ans = 0;
        while(i < len && str[i] >= '0' && str[i] <= '9') {
            vis = true;
            int t = str[i] - '0';
            // ans * 10 - t >= INT32_MIN
            // ans * 10 >= INT32_MIN + t
            if(ans < INT32_MIN / 10 || ans * 10 < INT32_MIN + t) return flag ? INT32_MIN : INT32_MAX;
            ans = ans * 10 - t;
            i++;
        }
        if(!vis) return 0;
        if(flag) return ans;
        if(ans == INT32_MIN) return INT32_MAX;
        return -ans;
    }
};

// 官方题解
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};
