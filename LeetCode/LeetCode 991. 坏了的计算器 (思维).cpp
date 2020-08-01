class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while(Y > X) {
            ans++;
            if(Y & 1) Y++;
            else Y >>= 1;
        }
        return ans + X - Y;
    }
};