// 方法一:  时间:O(n)   空间:O(n)
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector <vector<int>> sum;
        int i = 0, n = s.size();
        while(i < n) {
            char c = s[i];
            int cnt = 0;
            while(i < n && s[i] == c) {
                i++;
                cnt++;
            }
            sum.push_back({c - '0', cnt});
        }
        int ans = 0;
        for(int i = 0; i < sum.size() - 1; i++) {
            ans += min(sum[i][1], sum[i + 1][1]);
        }
        return ans;
    }
};

// 方法二:  时间:O(n)   空间:O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, i = 0, n = s.size(), last = 0;
        while(i < n) {
            char c = s[i];
            int now = 0;
            while(i < n && s[i] == c) {
                now++;
                i++;
            }
            ans += min(now, last);
            last = now;
        }
        return ans;
    }
};
