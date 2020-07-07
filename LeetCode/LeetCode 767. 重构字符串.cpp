class Solution {
public:
    string reorganizeString(string S) {
        vector <pair<int, int>> sum(30);
        int n = S.size();
        int len = n / 2 + (n & 1);
        for(auto &c : S) {
            int x = c - 'a';
            sum[x].first = x;
            sum[x].second++;
            if(sum[x].second > len) return "";
        }
        sort(sum.begin(), sum.end(), [](auto &x, auto &y) {
            return x.second > y.second;
        });
        string ans = S;
        int now = 0;
        for(auto &x : sum) {
            int num = x.second;
            char c = x.first + 'a';
            for(int i = 1; i <= num; i++) {
                if(now >= n) now = 1;
                ans[now] = c;
                now += 2;
            }
        }
        return ans;
    }
};