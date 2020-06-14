class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack <int> ss;
        ss.push(-1);
        int n = prices.size();
        vector <int> ans = prices;
        for(int i = 0; i < n; i++) {
            while(ss.top() != -1 && prices[i] <= prices[ss.top()]) {
                int k = ss.top();
                ss.pop();
                ans[k] = prices[k] - prices[i];
            }
            ss.push(i);
        }
        return ans;
    }
};