/*
1.答案为 0。
2.答案仅从当前不串联的数组中得到。(即k=1)
3.答案从 k = 2 的串联结果得到，第一部分的后缀和的最大值加上第二部分的前缀和的最大值。
4.答案从整个串联 k > 2 次后的结果得到，且一定是第一部分的后缀和的最大值，中间部分的总和，加上最后一部分的前缀和的最大值。
*/

class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        ll sum = 0, lmaxn = 0, rmaxn = 0, t = 0, ans = -0x3f3f3f;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(lmaxn < sum) {
                lmaxn = sum;
            }
            t += arr[i];
            ans = max(ans, t);
            if(t < 0) t = 0;
        }
        t = 0;
        for(int i = arr.size() - 1; i >= 0; i--) {
            t += arr[i];
            if(t > rmaxn) {
                rmaxn = t;
            }
        }
        if(k == 1) return ans;
        return max(lmaxn + rmaxn, max(lmaxn + rmaxn + sum * (k - 2), max(ans, 0ll))) % mod;
    }
};