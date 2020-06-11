class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack <int> ss;
        ss.push(-1);
        int n = T.size();
        vector <int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            while(ss.top() != -1 && T[i] > T[ss.top()]) {
                int k = i - ss.top();
                ans[ss.top()] = k;
                ss.pop();
            }
            ss.push(i);
        }
        return ans;
    }
};