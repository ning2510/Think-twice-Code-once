class Solution {
public:
    int m;
    vector <int> c;

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int i, int x) {
        while(i <= m) {
            c[i] += x;
            i += lowbit(i);
        }
        return ;
    }

    int get_sum(int i) {
        int ans = 0;
        while(i > 0) {
            ans += c[i];
            i -= lowbit(i);
        }
        return ans;
    }

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        m = n;
        c.resize(m + 1, 0);
        for(auto &x : bookings) {
            update(x[0], x[2]);
            update(x[1] + 1, -x[2]);
        }
        vector <int> ans(n, 0);
        for(int i = 1; i <= n; i++) {
            ans[i - 1] = get_sum(i);
        }
        return ans;
    }
};