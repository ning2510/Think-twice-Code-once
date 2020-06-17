class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        vector <int> maxn(n, 0);
        vector <int> minx(n, 1e6 + 5);
        if(A[n - 1] > A[0]) {
            for(int i = 0; i < n; i++) {
                if(i == 0) maxn[i] = A[0];
                else maxn[i] = max(maxn[i - 1], A[i]);
            }
            for(int i = n - 1; i >= 0; i--) {
                if(i == n - 1) minx[i] = A[i];
                else minx[i] = min(minx[i + 1], A[i]);
            }
            int l = 0;
            while(l < n && maxn[l] > minx[l + 1]) {
                l++;
            }
            return l + 1;
        }
        else {
            for(int i = n - 1; i >= 0; i--) {
                if(i == n - 1) maxn[i] = A[i];
                else maxn[i] = max(maxn[i + 1], A[i]);
            }
            for(int i = 0; i < n; i++) {
                if(i == 0) minx[i] = A[0];
                else minx[i] = min(minx[i - 1], A[i]);
            }
            int l = n - 1;
            while(l >= 0 && maxn[l] > minx[l - 1]) {
                l--;
            }
            return n - l;
        }
        return 0;
    }
};