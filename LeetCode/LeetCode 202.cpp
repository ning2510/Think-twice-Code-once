class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        set <int> ss;
        ss.insert(n);
        while(1) {
            int x = 0, m = n;
            while(m) {
                int t = m % 10;
                m /= 10;
                x += t * t;
            }
            if(ss.count(x)) return false;
            ss.insert(x);
            if(x == 1) return true; 
            n = x;
        }
    }
};
