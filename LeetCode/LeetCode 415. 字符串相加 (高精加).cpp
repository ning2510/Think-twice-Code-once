class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = min(num1.size(), num2.size());
        int m = max(num1.size(), num2.size());
        vector <int> ss(m, 0);
        for(int i = 0; i < n; i++) {
            ss[i] = (num1[i] - '0') + (num2[i] - '0');
        }
        for(int i = n; i < num1.size(); i++) ss[i] = num1[i] - '0';
        for(int i = n; i < num2.size(); i++) ss[i] = num2[i] - '0';
        string ans;
        for(int i = 0; i < ss.size(); i++) {
            if(i == ss.size() - 1) {
                if(ss[i] >= 10) {
                    ss.push_back(ss[i] / 10);
                    ss[i] %= 10;
                }
            }
            else {
                ss[i + 1] += ss[i] / 10;
                ss[i] %= 10;
            }
            ans += ss[i] + '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};