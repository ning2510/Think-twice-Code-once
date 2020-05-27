class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int f[n + 5];
        memset(f, 0x3f3f3f, sizeof(f));
        f[0] = cost[0];
        f[1] = cost[1];
        for(int i = 2; i < cost.size(); i++) {
            f[i] = min(f[i - 1], f[i - 2]) + cost[i];
        }
        return min(f[n - 1], f[n - 2]);
    }
};