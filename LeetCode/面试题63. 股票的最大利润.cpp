class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        int minx[n + 5];
        memset(minx, 0x3f3f3f, sizeof(minx));
        minx[0] = prices[0];
        for(int i = 1; i < n; i++) {
            minx[i] = min(minx[i - 1], prices[i]);
        }
        int ans = 0;
        for(int i = n - 1; i > 0; i--) {
            ans = max(ans, prices[i] - minx[i - 1]);
        }
        return ans;
    }
}; 