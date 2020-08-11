class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxn = INT_MIN, minx = INT_MAX;
        for(auto &x : A) {
            maxn = max(maxn, x);
            minx = min(minx, x);
        }
        maxn -= minx;
        if(maxn <= 2 * K) maxn = 0;
        else maxn -= 2 * K;
        return maxn;
    }
};