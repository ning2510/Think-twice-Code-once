//先对box数组按照一个维度进行排序，得到sorted_box序列，那么最终答案的序列就一定是sorted_box序列的某个子序列（这点很重要）。那么之后我们只需要找到这个总高度最大的子序列。
//dp[i]:以排序后的第个i箱子为顶的最高高度
class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        sort(box.begin(), box.end(), [](auto &x, auto &y) {
            return x[0] > y[0];
        });
        int ans = 0, n = box.size();
        vector <int> dp(n, 0);
        for(int i = 0; i < n; i++) {
            dp[i] = max(dp[i], box[i][2]);
            for(int j = i + 1; j < n; j++) {
                if(box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2]) {
                    dp[j] = max(dp[j], dp[i] + box[j][2]);
                    ans = max(ans, dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};