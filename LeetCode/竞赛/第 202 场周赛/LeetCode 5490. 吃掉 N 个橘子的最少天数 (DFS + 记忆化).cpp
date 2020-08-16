class Solution {
public:
    unordered_map <int, int> ss;
    
    int minDays(int n) {
        if(n < 2) return n;
        if(ss.count(n)) return ss[n];
        ss[n] = min(minDays(n / 2) + n % 2 + 1, minDays(n / 3) + n % 3 + 1);
        return ss[n];
    }
};