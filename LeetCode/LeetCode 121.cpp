class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int ans = 0, last = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < last) {
                last = min(last, prices[i]);
            }
            else {
                ans = max(ans, prices[i] - last);
            }
        }
        return ans;
    }
};