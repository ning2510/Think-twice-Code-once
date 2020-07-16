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
