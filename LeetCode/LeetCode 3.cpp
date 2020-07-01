/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 14时59分27秒
 ************************************************************************/

// 滑动窗口 + 数组记录位置  4ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int ans = 0, now = 0;
       int vis[128] = {0};
       for(int i = 0; i < s.size(); i++) {
            now = max(now, vis[(int)s[i]]);
            ans = max(ans, i - now + 1);
            vis[(int)s[i]] = i + 1;
       }
       return ans;
    }
};

// 暴力 36ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int ans = 0;
       int vis[128] = {0};
       for(int i = 0; i < s.size(); i++) {
           int now = 0;
           memset(vis, 0, sizeof(vis));
           for(int j = i ; j < s.size(); j++) {
               //int t = s[j] - '0'; 
               if(vis[(int)s[j]]) break;
               now++;
               vis[(int)s[j]] = 1;
           }
           ans = max(ans, now);
       } 
       return ans;
    }
};

//  滑动窗口  52ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l = 0, r = 0, ans = 0;
       set <char> ss;
       while(l < s.size() && r < s.size()) {
           if(!ss.count(s[r])) {
               ss.insert(s[r++]);
               ans = max(ans, r - l);
           }
           else {
               ss.erase(s[l++]);
           }
       }
       return ans;
    }
};

// 滑动窗口+map优化 28ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map <char, int> ss;
        int ans = 0, len = 0, last = 0;
        for(int i = 0; i < s.size(); i++) {
            if(ss.count(s[i])) {
                last = max(last, ss[s[i]] + 1);
            }
            ans = max(ans, i - last + 1);
            ss[s[i]] = i;
        }
        return ans;
    }
};
