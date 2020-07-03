class Solution {
public:
    int judge(int n, int k, int mid, vector<vector<int>>& matrix) {
        int i = n - 1, j = 0, sum = 0;
        while(i >= 0 && j < n) {
            if(matrix[i][j] <= mid) {
                sum += i + 1;
                j++;
            }
            else i--;
        }
        return sum >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int ans = -1, l = matrix[0][0], r = matrix[n - 1][n - 1];
        while(l <= r) {
            int mid = ((l ^ r) >> 1) + (l & r);
            if(judge(n, k, mid, matrix)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};