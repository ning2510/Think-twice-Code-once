/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时50分32秒
 ************************************************************************/

//回溯
class Solution {
public:
    vector<string> ss;
    string s;
    int vis[20], len;

    void dfs(string S) {
        if(s.size() == len) {
            ss.push_back(s);
        }
        for(int i = 0; i < len; i++) {
            if(vis[i]) continue;
            vis[i] = 1;
            s += S[i];
            dfs(S);
            vis[i] = 0;
            s.pop_back();
        }
        return ;
    }

    vector<string> permutation(string S) {
        if(S.size() == 0) {
            return ss;
        }
        len = S.size();
        dfs(S);
        return ss;
    }
};
