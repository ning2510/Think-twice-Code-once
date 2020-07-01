class Solution {
private:
    vector <int> days;
    vector <int> costs;
    vector <int> ans;
    int a[3] = {1, 7, 30};

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;
        ans.assign(days.size(), -1);
        return dp(0);
    }

    int dp(int x) {
        if(x >= days.size()) return 0;
        if(ans[x] != -1) return ans[x];
        ans[x] = INT_MAX;
        int j = x;
        for(int i = 0; i < 3; i++) {
            while(j < days.size() && days[j] < days[x] + a[i]) j++;
            ans[x] = min(ans[x], dp(j) + costs[i]);
        }
        return ans[x];
    }
};