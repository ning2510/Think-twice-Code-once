class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, sum = 0;
        for(auto &x : s) {
            if(x == '(') {
                if(sum & 1) {
                    sum--;
                    ans++;
                }
                sum += 2;
            }
            else sum--;
            if(sum < 0) {
                int cnt = abs(sum) / 2 + abs(sum) % 2;
                sum += cnt * 2;
                ans += cnt;
            }
        }
        ans += sum;
        return ans;
    }
};