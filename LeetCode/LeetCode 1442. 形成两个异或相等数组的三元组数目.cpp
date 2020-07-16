/*
方法1： 先用数据记录前缀异或和，然后暴力枚举三个区间

方法2：题目中两端异或和相等，其实就是整个区间的异或和为零。所以只需要找到数组中异或和为零的区间。然后这个区间可拆分为任意两个，这两个的异或和都相等。

所以某个长度k的异或的为零的区间，对应着k-1种分法。

所以可以使用哈希表存储前面每个值的前缀异或和出现的各个位置，然后直接求解。
*/

// 方法一：暴力  时间复杂度：O(n^3)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector <int> s(n + 1, 0);
        for(int i = 0; i < n; i++) {
            s[i + 1] = s[i] ^ arr[i];
        }
        int ans = 0;
        for(int k = 1; k <= n; k++) {
            for(int j = 1; j <= k; j++) {
                for(int i = 1; i < j; i++) {
                    if((s[j - 1] ^ s[i - 1]) == (s[k] ^ s[j - 1])) ans++;
                }
            }
        }
        return ans;
    }
};

// 方法二：哈希  时间复杂度：O(n^2)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map <int, vector<int>> ss;
        int ans = 0, now = 0, n = arr.size();
        ss[0].push_back(0);
        for(int i = 1; i <= n; i++) {
            now ^= arr[i - 1];
            for(auto &x : ss[now]) {
                ans += i - (x + 1) + 1 - 1;
            }
            ss[now].push_back(i);
        }
        return ans;
    }
};
