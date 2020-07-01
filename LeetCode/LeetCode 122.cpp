class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int ans = 0, now = -1;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] > now) {
                if(now == -1) now = prices[i];
                else {
                    if(i != prices.size() - 1 && prices[i + 1] > prices[i]) continue;
                    ans += prices[i] - now;
                    now = -1;
                }
            }
            else now = prices[i];
        }
        return ans;
    }
};