class Solution {
public:
    int hammingDistance(int x, int y) {
        int t, ans = 0;
        for(int i = 0; i < 31; i++) {
            t = (1 << i);
            if((t & x) != (t & y)) ans++;
        }
        return ans;
    }
};