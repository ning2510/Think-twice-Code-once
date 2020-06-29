class Solution {
public:
    int judge(int n, int m, int mid, int threshold, vector<vector<int>>& mat, vector<vector<int>>& sum) {
        if(mid == 0) return 0;
        int x, y;
        for(int i = mid; i <= n; i++) {
            for(int j = mid; j <= m; j++) {
                x = i - mid;
                y = j - mid;
                if(sum[i][j] - sum[x][j] - sum[i][y] + sum[x][y] <= threshold) return 1;
            }
        }
        return 0;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector <vector<int>> sum(n + 1, vector <int> (m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int ans = 0, l = 0, r = min(n, m);
        while(l <= r) {
            int mid = ((l ^ r) >> 1) + (l & r);
            if(judge(n, m, mid, threshold, mat, sum)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};