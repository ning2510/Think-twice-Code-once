class Solution {
public:
    vector <int> maxn;

    int judge(int mid, int m, vector <int>& time) {
        int sum = 0, now = 0, mx = 0;
        for(int i = 0; i < time.size(); i++) {
            mx = max(mx, time[i]);
            if(now + time[i] - mx <= mid) {
                now += time[i];
            }
            else {
                sum++;
                now = time[i];
                mx = time[i];
                if(sum > m) return 0;
            }
            if(i == time.size() - 1) {
                sum++;
            }
        }
        return sum <= m;
    }

    int minTime(vector<int>& time, int m) {
        int n = time.size();
        maxn.resize(n, 0);
        for(int i = 0; i < n; i++) {
            if(i == 0) maxn[i] = time[i];
            else maxn[i] = max(maxn[i - 1], time[i]);
        }
        int ans = -1, l = 0, r = 1e9 + 7;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(judge(mid, m, time)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};