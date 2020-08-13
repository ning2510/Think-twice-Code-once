class Solution {
public:
    string multiply(string num1, string num2) {
        vector <int> ss(200, 0);
        vector <int> pp(200, 0);
        int n = num1.size(), m = num2.size();
        for(int i = n - 1; i >= 0; i--) {
            ss[n - i] = num1[i] - '0';
        }
        for(int i = m - 1; i >= 0; i--) {
            pp[m - i] = num2[i] - '0';
        }
        vector <int> ans(200, 0);
        for(int i = 1; i <= n; i++) {
            int x = 0;
            for(int j = 1; j <= m; j++) {
                ans[i + j - 1] += ss[i] * pp[j] + x;
                x = ans[i + j - 1] / 10;
                ans[i + j - 1] %= 10;
            }
            ans[i + m] = x;
        }
        int len = n + m;
        while(ans[len] == 0 && len > 1) len--;
        string now;
        for(int i = len; i > 0; i--) {
            now += ans[i] + '0';
        } 
        return now;
    }
};