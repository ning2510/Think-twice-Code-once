class Solution {
public:
    int mySqrt(int x) {
        int ans;
        for(long long i = 1; i; i++) {
            if(i * i == x) {
                ans = i;
                break;
            }
            else if(i * i > x) {
                ans = i - 1;
                break;
            }
        }
        return ans;
    }
};