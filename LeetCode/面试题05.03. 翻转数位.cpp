class Solution {
public:
    int reverseBits(int num) {
        int ans = 0, cnt = 0, pre_cnt = 0;
        while(num) {
            if(num & 1) {
                cnt++;
            }
            else {
                ans = max(ans, cnt + pre_cnt + 1);
                pre_cnt = cnt;
                cnt = 0;
            }
            num >>= 1;
        }
        return max(ans, cnt + pre_cnt + 1);
    }
};