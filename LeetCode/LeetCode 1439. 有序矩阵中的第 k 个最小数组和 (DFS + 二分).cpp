class Solution {
public:
    int n, m, cnt;
    vector<vector<int>> ss;

    //sum有初值，即每行的第一列
    //这样做的好处就是dfs时每行都可以进行cnt++，而不用到最后一样再判断，这样可以剪枝掉更多部分节省时间
    void dfs(int mid, int deep, int sum, int k) {
        if(cnt >= k || deep == n) return ;
        dfs(mid, deep + 1, sum, k);
        for(int i = 1; i < m; i++) {
            sum += ss[deep][i] - ss[deep][0];
            if(sum > mid) break;
            cnt++;
            dfs(mid, deep + 1, sum, k);
            sum -= ss[deep][i] - ss[deep][0];
        }
        return ;
    }

    int judge(int mid, int k, int p) {
        cnt = 1;
        dfs(mid, 0, p, k);
        return cnt >= k;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        n = mat.size();
        m = mat[0].size();
        ss = mat;
        int l = 0, r = 0;
        for(int i = 0; i < n; i++) {
            l += mat[i][0];
            r += mat[i][m - 1];
        }
        int ans, p = l;
        while(l <= r) {
            int mid = ((l ^ r) >> 1) + (l & r);
            if(judge(mid, k, p)) {
                ans = mid;
                r = mid - 1;
            } 
            else l = mid + 1;
            //cout << l << ' ' << r << ' ' << mid << ' '<< cnt << endl;
        }
        return ans;
    }
};