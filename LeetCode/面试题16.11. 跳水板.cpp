class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0) return {};
        if(shorter == longer) return {shorter * k};
        vector <int> ans(k + 1, 0);
        for(int i = 0; i <= k; i++) {
            ans[i] = shorter * (k - i) + longer * i;
        }
        return ans;
    }
};