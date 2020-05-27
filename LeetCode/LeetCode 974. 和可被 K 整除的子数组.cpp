class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map <int, int> ss = {{0, 1}};
        int sum = 0, ans = 0;
        for(auto &x : A) {
            sum += x;
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            int t = (sum % K + K) % K;
            if(ss.count(t)) {
                ans += ss[t];
            }
            ss[t]++;
        }
        return ans;
    }
};