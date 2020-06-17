class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = -1005, n = A.size() - 1, mx = A[n] - n;
        for(int i = n - 1; i >= 0; i--) {
            ans = max(ans, A[i] + i + mx);
            mx = max(mx, A[i] - i);
        }
        return ans;
    }
};