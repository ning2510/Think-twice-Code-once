//dp + 单调栈 （与 LeetCode 84 相似）
class Solution {
public:
    int js(vector<int>& f) {
        stack <int> ss;
        ss.push(-1);
        int ans = 0, height, width;
        for(int i = 0; i < f.size(); i++) {
            while(ss.top() != -1 && f[i] <= f[ss.top()]) {
                height = f[ss.top()];
                ss.pop();   //注意这里，已出栈一个元素
                width = i - ss.top() - 1;
                ans = max(ans, height * width);
            }
            ss.push(i);
        }
        while(ss.top() != -1) {
            height = f[ss.top()];
            ss.pop();   //注意这里，已出栈一个元素
            width = f.size() - ss.top() - 1;
            ans = max(ans, height * width);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> f(m, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') f[j] = f[j] + 1;
                else f[j] = 0;
            }
            ans = max(ans, js(f));
        }
        return ans;
    }
};