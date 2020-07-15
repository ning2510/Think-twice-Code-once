class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ans = 0, n = A.size();
        int l = 0, r = 0, sum_l = 0, sum_r = 0;
        for(int i = 0; i < n; i++) {
            sum_l += A[i];
            while(l < i && sum_l > S) sum_l -= A[l++];
            sum_r += A[i];
            while(r < i && (sum_r > S || (sum_r == S && A[r] == 0))) sum_r -= A[r++];
            if(sum_l == S) ans += r - l + 1;
        }
        return ans;
    }
};