class Solution {
public:
    int judge(int mid, int m, int k, vector <int>& bloomDay) {
        int sum = 0, now = 0;
        for(auto &x : bloomDay) {
            if(mid >= x) {
                now++;
                if(now == k) {
                    sum++;
                    now = 0;
                    if(sum >= m) return 1;
                }
            }
            else now = 0;
        }
        return sum >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m * k > n) return -1;
        int ans = -1, l = 0, r = 1e9 + 7;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(judge(mid, m, k, bloomDay)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};