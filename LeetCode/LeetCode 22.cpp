/*************************************************************************
	> File Name: bbb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月09日 星期四 10时09分51秒
 ************************************************************************/

class Solution {
public:
    vector <string> ss;

    void dfs(string s, int num0, int num1, int n, int sum) {
        if(num0 == n && num1 == n && sum == 0) {
            ss.push_back(s);
            return ;
        }
        if(num0 > n || num1 > n || sum < 0) return ;
        if(sum >= 0) {
            string p = s + '(';
            //if(num1 + 1 > n) return ;  这里不能出现,若 '(' 不满足跳出则 ')'不会被匹配
            dfs(p, num0, num1 + 1, n, sum + 1);
        }
        if(sum > 0) {
            string k = s + ')';
            if(num0 + 1 > n || sum - 1 < 0) return ;
            dfs(k, num0 + 1, num1, n, sum - 1);
        }
        return ;
    }

    vector<string> generateParenthesis(int n) {
        string s;
        dfs(s, 0, 0, n, 0);
        return ss;
    }
};
