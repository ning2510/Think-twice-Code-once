class Solution {
public:
    int kthFactor(int n, int k) {
        vector <int> ss;
        ss.push_back(-1);
        int now = 0, flag = 0;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                now++;
                ss.push_back(i);
                if(now == k) return i;
            }
            if(i * i == n) flag = 1;
        }
        k -= now;
        int index = now - k + 1 - flag;
        return index == 0 ? -1 : n / ss[index];
    }
};