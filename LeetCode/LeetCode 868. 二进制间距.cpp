class Solution {
public:
    int binaryGap(int N) {
        int ans = 0, now = 0, sta = -1, end = -1;
        while(N) {
            now++;
            if(N & 1) {
                if(sta == -1) {
                    sta = end = now;
                }
                else {
                    sta = end;
                    end = now;
                    ans = max(ans, end - sta);
                }
            }
            N >>= 1;
        }
        return ans;
    }
};