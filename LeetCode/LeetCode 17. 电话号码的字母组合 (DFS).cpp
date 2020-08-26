class Solution {
public:
    map <int, string> ss;
    vector <string> ans;

    void dfs(int x, int n, string& now, string digits) {
        if(x == n) {
            if(now.size()) ans.push_back(now);
            return ;
        }
        int cnt = digits[x] - '0';
        for(int i = 0; i < ss[cnt].size(); i++) {
            string p = now + ss[cnt][i];
            dfs(x + 1, n, p, digits);
        }
        return ;
    }

    vector<string> letterCombinations(string digits) {
        ss[2] = "abc";
        ss[3] = "def";
        ss[4] = "ghi";
        ss[5] = "jkl";
        ss[6] = "mno";
        ss[7] = "pqrs";
        ss[8] = "tuv";
        ss[9] = "wxyz";
        string s;
        dfs(0, digits.size(), s, digits);
        return ans;
    }
};