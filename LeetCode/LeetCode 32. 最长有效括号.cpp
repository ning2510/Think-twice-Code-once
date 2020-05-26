// 方法一：栈
class Solution {
public:
    int longestValidParentheses(string s) {
        stack <int> ss;
        ss.push(-1);
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') ss.push(i);
            else {
                ss.pop();
                if(ss.empty()) ss.push(i);
                else ans = max(ans, i - ss.top());
            }
        }
        return ans;
    }
};

// 方法二：动态规划
class Solution {
public:
    int longestValidParentheses(string s) {
        int f[s.size() + 5];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == ')') {
                if(s[i - 1] == ')') {
                    if(i - 1 - f[i - 1] >= 0 && s[i - 1 - f[i - 1]] == '(') {
                        f[i] = f[i - 1] + 2 + (i - f[i - 1] - 1 >= 1 ? f[i - f[i - 1] - 2] : 0);
                    }
                }
                else {
                    if(i >= 2) f[i] = f[i - 2] + 2;
                    else f[i] = 2;
                }
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
