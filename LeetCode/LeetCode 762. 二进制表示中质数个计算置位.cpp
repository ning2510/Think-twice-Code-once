class Solution {
public:
    int judge(int x) {
        if(x < 2) return 0;
        for(int i = 2; i * i <= x; i++) {
            if(x % i == 0) return 0;
        }
        return 1;
    }

    int countPrimeSetBits(int L, int R) {
        int ans = 0, now = 0;
        for(int i = L; i <= R; i++) {
            int x = i;
            now = 0;
            while(x) {
                x &= x - 1;
                now++;
            }
            if(judge(now)) ans++;
        }
        return ans;
    }
};