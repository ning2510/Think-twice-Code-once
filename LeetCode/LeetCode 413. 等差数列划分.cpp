class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0, i = 0, n = A.size();
        if(n < 3) return 0;
        while(i + 2 < n) {
            int now = i + 1;
            int c = A[now] - A[now - 1];
            while(now < n && A[now] - A[now - 1] == c) {
                now++;
            }
            int len = now - i;
            if(len > 2) ans += (len - 1) * (len - 2) / 2;
            i = now - 1;
        }
        return ans;
    }
};