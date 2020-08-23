class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0, i = 0, j = piles.size() - 1;
        while(i < j) {
            ans += piles[j - 1];
            i++;
            j -= 2;
        }
        return ans;
    }
};